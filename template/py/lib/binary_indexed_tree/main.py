import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from heapq import heappop, heappush
from operator import itemgetter


class Bit:
    ''' 数列に対し, ある要素に値を加える操作と,
    区間和を求める操作をそれぞれ対数時間で行うことが出来るデータ構造。
    計算量: O(logN)'''

    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

    def sum(self, i):
        ''' 区間[1, i]の合計を求める。
        '''
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        '''要素iに値xを加える。
        '''
        while i <= self.size:
            self.tree[i] += x
            i += i & -i


# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
n, q = map(int, input().split())
bit = Bit(n)
while q > 0:
    com, x, y = map(int, input().split())
    if com == 0:
        bit.add(x, y)
    else:
        print(bit.sum(y) - bit.sum(x-1))
    q -= 1
