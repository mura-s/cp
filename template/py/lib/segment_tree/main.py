import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from decimal import Decimal
from heapq import heappop, heappush
from operator import itemgetter

INF = (1 << 31) - 1


class SegmentTree:
    """セグメント木による RMQ (Range Minimum Query) の実装
    RMQ以外にする場合は、fnに別の関数を渡す

    計算量
    - 初期化: O(nlogn)
      - O(n)でも実装できるが、O(nlogn)の実装になっている
      - init後にupdateで初期化
    - update: O(logn)
    - query: O(logn)
    """

    def __init__(self, n, fn=lambda x, y: min(x, y)):
        """簡単のため、要素数を2のべき乗に"""
        self.n = 1
        while self.n < n:
            self.n *= 2
        self.arr = [INF for _ in range(2 * self.n - 1)]
        self.fn = fn

    def update(self, i, x):
        """i番目の値 (0-indexed) をxに変更"""
        k = self.n + i - 1
        self.arr[k] = x
        while k > 0:
            k = (k - 1) // 2
            self.arr[k] = self.fn(self.arr[2 * k + 1], self.arr[2 * k + 2])

    def query(self, l, r):
        """[l, r) の最小値を求める"""
        return self._inner_query(l, r, 0, 0, self.n)

    def _inner_query(self, l, r, k, il, ir):
        """private method
        [l, r) の最小値を求める
        後ろのほうの引数は、計算の簡単のための引数。
        kは節点の番号、il, irはその節点が [il, ir) に対応づいていることを表す。
        したがって、外からは _inner_query(l, r, 0, 0, n) として呼ぶ。
        """
        if ir <= l or r <= il:
            return INF

        elif l <= il and ir <= r:
            return self.arr[k]

        vl = self._inner_query(l, r, k * 2 + 1, il, (il + ir) // 2)
        vr = self._inner_query(l, r, k * 2 + 2, (il + ir) // 2, ir)
        return self.fn(vl, vr)


# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
n, q = map(int, input().split())
st = SegmentTree(n)
for i in range(q):
    com, x, y = map(int, input().split())
    if com == 0:
        st.update(x, y)
    else:
        print(st.query(x, y + 1))
