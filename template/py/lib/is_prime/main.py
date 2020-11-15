import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from heapq import heappop, heappush
from operator import itemgetter


def is_prime(x: int):
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True


a = 13
b = 15
print(is_prime(a))
print(is_prime(b))
