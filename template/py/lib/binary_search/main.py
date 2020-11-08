import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from heapq import heappop, heappush
from operator import itemgetter


class BinarySearch:
    def __init__(self, lis):
        self._lis = lis  # list

    def search(self, v: int):
        left = 0
        right = len(self._lis)  # always satisfied with the check.
        while left < right:
            mid = (left + right) // 2
            if (self._lis[mid] == v):
                return True
            elif (self._lis[mid] < v):
                left = mid + 1
            else:
                right = mid
        return False


# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja
n = int(input())
s = list(map(int, input().split()))
q = int(input())
t = list(map(int, input().split()))

bs = BinarySearch(s)
cnt = 0
for v in t:
    if bs.search(v):
        cnt += 1
print(cnt)
