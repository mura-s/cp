import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from decimal import Decimal
from heapq import heappop, heappush
from operator import itemgetter


def prime_factor(n: int):
    """素因数分解
    素数の値と個数のpairのvectorを返す
    """
    l = []
    p = 2
    while p * p <= n:
        if n % p != 0:
            continue
        num = 0
        while n % p == 0:
            num += 1
            n //= p
        l.append((p, num))
        p += 1
    if n != 1:
        l.append((n, 1))
    return l


m = 48
primes = prime_factor(m)
for p in primes:
    print("{} {}".format(p[0], p[1]))
