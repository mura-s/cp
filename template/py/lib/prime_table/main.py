import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from decimal import Decimal
from heapq import heappop, heappush
from operator import itemgetter


def eratosthenes(n: int):
    primes = []
    isPrime = [True for _ in range(n+1)]
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, n+1):
        if not isPrime[i]:
            continue
        primes.append(i)
        for j in range(2*i, n+1, i):
            isPrime[j] = False
    return primes


n = 100
primes = eratosthenes(n)
for p in primes:
    print(p)
