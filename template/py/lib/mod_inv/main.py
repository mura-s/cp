import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from heapq import heappop, heappush
from operator import itemgetter

MOD = 10 ** 9 + 7


def modinv(a: int):
    """拡張 Euclid の互除法を用いて、mod MOD での a の逆元 a^{-1} を計算する
    計算量: O(logMOD)

    ref. https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#3-%E5%89%B2%E3%82%8A%E7%AE%97-a--b
    """
    b = MOD
    u = 1
    v = 0
    while b > 0:
        t = a // b

        a -= t * b
        a, b = b, a

        u -= t * v
        u, v = v, u
    u %= MOD
    return u


x = 678813585
y = 100000
# (x / y) % MOD を計算
print(x * modinv(y) % MOD)
