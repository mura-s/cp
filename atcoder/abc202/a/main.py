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

a, b, c = map(int, input().split())

ans = 21 - a - b - c
print(ans)
