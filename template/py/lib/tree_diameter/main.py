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
    def __init__(self, to: int, cost: int):
        self._to = to
        self._cost = cost

    def to(self):
        return self._to

    def cost(self):
        return self._cost


MAX_V = 100001
g = [[] for _ in range(MAX_V)]


def dfs(idx: int, parent: int):
    ret = (0, idx)
    for e in g[idx]:
        if e.to() == parent:
            continue
        cost = dfs(e.to(), idx)
        cost = (cost[0] + e.cost(), cost[1])
        if ret[0] < cost[0]:
            ret = cost
    return ret


def tree_diameter():
    """重み付き木の直径を求める. (重みが与えられていない場合は, 全ての重みを1とする.)
    頂点数をNとして、計算量は O(N).
    """
    p = dfs(0, -1)
    q = dfs(p[1], -1)
    return q[0]


# Fix RecursionError: maximum recursion depth exceeded
sys.setrecursionlimit(200000)

# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp
n = int(input())
for i in range(n - 1):
    s, t, w = map(int, input().split())
    g[s].append(Edge(t, w))
    g[t].append(Edge(s, w))
ans = tree_diameter()
print(ans)
