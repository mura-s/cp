import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from heapq import heappop, heappush
from operator import itemgetter


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


# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp
n, q = map(int, input().split())
uf = UfTree(n)
for i in range(q):
    com, xi, yi = map(int, input().split())
    if com == 0:
        uf.unite(xi, yi)
    else:
        print(1 if uf.same(xi, yi) else 0)
