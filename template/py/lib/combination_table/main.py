import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from heapq import heappop, heappush
from operator import itemgetter

MAX_NUM = 10 ** 6 + 3
MOD = 10 ** 9 + 7


class CombTable:
    def __init__(self):
        """fac[n]: n!
        finv[n]: (n!)^-1
        inv[n]: nの逆元
        """
        self.fac = [0 for _ in range(MAX_NUM)]
        self.finv = [0 for _ in range(MAX_NUM)]
        self.inv = [0 for _ in range(MAX_NUM)]
        self.fac[0] = self.fac[1] = 1
        self.finv[0] = self.finv[1] = 1
        self.inv[1] = 1
        for i in range(2, MAX_NUM):
            self.fac[i] = self.fac[i - 1] * i % MOD
            self.inv[i] = MOD - self.inv[MOD % i] * (MOD // i) % MOD
            self.finv[i] = self.finv[i - 1] * self.inv[i] % MOD

    def comb(self, n: int, k: int):
        """二項係数計算 (combination)
        nCk = (n!) * (k!)^-1 * ((n-k)!)^-1 として計算
        """
        if n < k:
            return 0
        if n < 0 or k < 0:
            return 0
        return self.fac[n] * (self.finv[k] * self.finv[n - k] % MOD) % MOD


# https://atcoder.jp/contests/abc034/tasks/abc034_c
w, h = map(int, input().split())
ct = CombTable()
print(ct.comb(w - 1 + h - 1, w - 1))
