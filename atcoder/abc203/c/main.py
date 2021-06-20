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

n, k = map(int, input().split())
d = {}
for i in range(n):
    a, b = map(int, input().split())
    if a not in d:
        d[a] = 0
    d[a] += b

pos = 0
sorted_d = sorted(d.items())
for a, b in sorted_d:
    if a - pos > k:
        break
    else:
        k -= a - pos
        k += b
        pos = a

pos += k
print(pos)
