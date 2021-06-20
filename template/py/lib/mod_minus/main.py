import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from heapq import heappop, heappush
from operator import itemgetter

MOD = 10 ** 9 + 7

# マイナスでも普通に % MOD すればよい
a = 2000000020
b = 20
ans1 = ((a % MOD) - (b % MOD)) % MOD
ans2 = ((b % MOD) - (a % MOD)) % MOD
print(a % MOD)
print(b % MOD)
print(ans1)
print(ans2)
