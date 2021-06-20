import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from heapq import heappop, heappush
from operator import itemgetter


def nCr(n: int, r: int):
    """ref. https://www.kaoken.cg0.xyz/math_combination/
    組み合わせ (combination) を求める
    """
    if r > n:
        return 0
    if r == 0 or n == r:
        return 1
    if r * 2 > n:
        r = n - r
    result = n
    for i in range(2, r + 1):
        result *= n - i + 1
        result //= i
    return result


def nHr(n: int, r: int):
    """重複組み合わせを求める
    r個のものをn種類にわける
    ref. https://mathtrain.jp/tyohukuc
    """
    return nCr(n + r - 1, r)


print(nCr(10, 0))
print(nCr(10, 1))
print(nCr(10, 3))
print(nCr(10, 9))
print(nCr(10, 10))
print(nHr(7, 3))
