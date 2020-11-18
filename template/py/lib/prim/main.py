import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from decimal import Decimal
from heapq import heappop, heappush
from operator import itemgetter, truediv

MAX_V = 10001
g = [[] for _ in range(MAX_V)]


class Edge:
    def __init__(self, to: int, cost: int):
        self._to = to
        self._cost = cost

    def to(self):
        return self._to

    def cost(self):
        return self._cost


def prim(v: int):
    '''最小全域木 (全域木のうち、その辺群の重みの総和が最小になる木)
    を求めるアルゴリズム
    https://ei1333.github.io/luzhiled/snippets/graph/prim.html
    計算量: O(ElogV)
    '''
    ans = 0
    used = [False for _ in range(v)]
    que = []
    heappush(que, (0, 0))  # (cost, pos)
    while que:
        p = heappop(que)
        pos = p[1]
        if used[pos]:
            continue
        used[pos] = True
        ans += p[0]
        for i in range(len(g[pos])):
            heappush(que, (g[pos][i].cost(), g[pos][i].to()))
    return ans


# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
v, e = map(int, input().split())
for i in range(e):
    si, ti, wi = map(int, input().split())
    g[si].append(Edge(ti, wi))
    g[ti].append(Edge(si, wi))
print(prim(v))
