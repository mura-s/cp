import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from decimal import Decimal
from heapq import heappop, heappush
from operator import itemgetter

INF = 2000000000
MAX_V = 102

d = [[] for _ in range(MAX_V)]
for i in range(MAX_V):
    d[i] = [0 for _ in range(MAX_V)]


def warshall_floyd(v: int):
    '''隣接行列で表されるグラフの全点間最短路を求めるアルゴリズム。
    負辺があっても動作する。負閉路が存在する場合はそれも検出する。
    https://ei1333.github.io/luzhiled/snippets/graph/warshall-floyd.html

    計算量: O(V^3)
    '''
    for k in range(v):
        for i in range(v):
            for j in range(v):
                if d[i][k] == INF or d[k][j] == INF:
                    continue
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])


#  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp
v, e = map(int, input().split())
for i in range(v):
    for j in range(v):
        if i == j:
            d[i][j] = 0
        else:
            d[i][j] = INF

for i in range(e):
    si, ti, di = map(int, input().split())
    d[si][ti] = di

warshall_floyd(v)
for i in range(v):
    if d[i][i] < 0:
        print('NEGATIVE CYCLE')
        exit()

for i in range(v):
    for j in range(v):
        if j != 0:
            print(' ', end='')
        if d[i][j] == INF:
            print('INF', end='')
        else:
            print(d[i][j], end='')
    print('')
