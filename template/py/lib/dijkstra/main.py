import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from heapq import heappop, heappush
from operator import countOf, itemgetter

INF = (1 << 30) - 1
MAX_V = 10 ** 6 + 1
graph = [[] for _ in range(MAX_V)]
dist = [INF for _ in range(MAX_V)]
prev_path = [-1 for _ in range(MAX_V)]


class Edge:
    def __init__(self, to: int, cost: int):
        self._to = to
        self._cost = cost

    def to(self):
        return self._to

    def cost(self):
        return self._cost


def dijkstra(s: int):
    """負辺のない単一始点全点間最短路を求めるアルゴリズム。
    蟻本参照
    計算量: O(ElogV)
    """
    pq = []
    heappush(pq, (0, s))  # (cost, pos)
    dist[s] = 0

    while pq:
        (cost, cur) = heappop(pq)
        if dist[cur] < cost:
            continue
        for next in graph[cur]:
            if dist[next.to()] > cost + next.cost():
                heappush(pq, (cost + next.cost(), next.to()))
                dist[next.to()] = cost + next.cost()
                prev_path[next.to()] = cur


def get_path(e: int):
    """経路復元"""
    path = []
    while e != -1:
        path.append(e)
        e = prev_path[e]
    path.reverse()
    return path


# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
v, e, r = map(int, input().split())
for _ in range(e):
    si, ti, di = map(int, input().split())
    graph[si].append(Edge(ti, di))

dijkstra(r)
for i in range(v):
    if dist[i] == INF:
        print("INF")
    else:
        print(dist[i])
