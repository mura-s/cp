import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from heapq import heappop, heappush
from operator import itemgetter

MOD = 10**9 + 7

m, n = map(int, input().split())
ans = pow(m, n, MOD)
print(ans)
