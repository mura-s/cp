import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from decimal import Decimal
from heapq import heappop, heappush
from operator import itemgetter

sys.setrecursionlimit(10**6)
# INF = (1 << 30) - 1
# LL_INF = (1 << 62) - 1
# MOD = 10**9 + 7

sx, sy, gx, gy = map(int, input().split())

ratio = sy / (sy + gy)
dx = abs(sx - gx) * ratio
if sx >= gx:
    ans = sx - dx
else:
    ans = sx + dx
print('{:.10f}'.format(ans))
