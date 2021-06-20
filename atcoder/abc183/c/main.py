import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from decimal import Decimal
from heapq import heappop, heappush
from operator import itemgetter

sys.setrecursionlimit(10 ** 6)

n, k = map(int, input().split())
t = [[] for _ in range(n)]
for i in range(n):
    ti = list(map(int, input().split()))
    t[i] = ti

ans = 0
l = [i for i in range(1, n)]
for x in itertools.permutations(l):
    s = 0
    pos = 0
    for e in x:
        s += t[pos][e]
        pos = e
    s += t[pos][0]
    if s == k:
        ans += 1

print(ans)
