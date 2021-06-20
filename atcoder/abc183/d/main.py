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
# INF = (1 << 30) - 1
# LL_INF = (1 << 62) - 1
# MOD = 10**9 + 7

MAX_T = 2 * 10 ** 5 + 1

n, w = map(int, input().split())
imos = [0 for _ in range(MAX_T)]
for _ in range(n):
    si, ti, pi = map(int, input().split())
    imos[si] += pi
    imos[ti] -= pi
if imos[0] > w:
    print("No")
    exit()
for i in range(1, MAX_T):
    imos[i] += imos[i - 1]
    if imos[i] > w:
        print("No")
        exit()
print("Yes")
