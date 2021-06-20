import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from decimal import Decimal
from heapq import heappop, heappush
from operator import itemgetter


class Edge:
    def __init__(self, u: int, v: int, cost: int):
        self._u = u
        self._v = v
        self._cost = cost

    def u(self):
        return self._u

    def v(self):
        return self._v

    def cost(self):
        return self._cost


class UfTree:
    def __init__(self, n: int):
        self._par = [i for i in range(n)]
        self._sizes = [1 for _ in range(n)]

    def find(self, x: int):
        if x == self._par[x]:
            return x
        self._par[x] = self.find(self._par[x])
        return self._par[x]

    def unite(self, x: int, y: int):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if self._sizes[x] < self._sizes[y]:
            x, y = y, x
        self._par[y] = x
        self._sizes[x] += self._sizes[y]

    def same(self, x: int, y: int):
        return self.find(x) == self.find(y)

    def size(self, x: int):
        return self._sizes[self.find(x)]


def kruskal(es, v: int, e: int):
    """最小全域木 (全域木のうち、その辺群の重みの総和が最小になる木)
    を求めるアルゴリズム
    計算量: O(ElogV)

    es: Edge list
    """
    sorted_es = sorted(es, key=lambda e: e.cost())
    uf = UfTree(v)
    res = 0
    for i in range(e):
        e = sorted_es[i]
        if not uf.same(e.u(), e.v()):
            uf.unite(e.u(), e.v())
            res += e.cost()
    return res


# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
v, e = map(int, input().split())
es = []
for _ in range(e):
    si, ti, wi = map(int, input().split())
    es.append(Edge(si, ti, wi))
ans = kruskal(es, v, e)
print(ans)
