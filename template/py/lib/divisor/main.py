import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from heapq import heappop, heappush
from operator import itemgetter


def divisor(n: int):
    '''約数列挙
    '''
    res = []
    i = 1
    while i * i <= n:
        if n % i == 0:
            res.append(i)
            if i != n // i:
                res.append(n // i)
        i += 1
    return res


n = 36
divs = divisor(n)
for d in divs:
    print(d)
