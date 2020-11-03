import collections
import math
import sys


class Edge:
    def __init__(self, f: int, t: int, c: int):
        self._from = f
        self._to = t
        self._cost = c

    def f(self):
        return self._from

    def t(self):
        return self._to

    def c(self):
        return self._cost


INF = (1 << 30) - 1
MAX_V = 1001
MAX_E = 2001
es = [Edge(0, 0, 0) for _ in range(MAX_E)]
d = [INF for _ in range(MAX_V)]


def bellman_ford(s: int, v: int, e: int):
    d[s] = 0
    for _ in range(0, v-1):
        for j in range(0, e):
            edge = es[j]
            if d[edge.f()] == INF:
                continue
            d[edge.t()] = min(d[edge.t()], d[edge.f()] + edge.c())

    for j in range(0, e):
        edge = es[j]
        if d[edge.f()] == INF:
            continue
        if d[edge.f()] + edge.c() < d[edge.t()]:
            return False

    return True


# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp
v, e, r = map(int, input().split())
for i in range(0, e):
    si, ti, di = map(int, input().split())
    es[i] = Edge(si, ti, di)

flag = bellman_ford(r, v, e)
if not flag:
    print('NEGATIVE CYCLE')
    exit()

for i in range(0, v):
    if d[i] == INF:
        print('INF')
    else:
        print(d[i])
