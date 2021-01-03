import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from decimal import Decimal
from heapq import heappop, heappush
from operator import itemgetter
from typing import List

sys.setrecursionlimit(10**6)
INF = (1 << 30) - 1
# LL_INF = (1 << 62) - 1
# MOD = 10**9 + 7


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        ans = 0.0
        sum_len = len(nums1) + len(nums2)
        mid = (sum_len - 1) // 2
        i = 0
        j = 0
        cnt = 2 if sum_len % 2 == 0 else 1
        while True:
            next_nums1 = nums1[i] if i < len(nums1) else INF
            next_nums2 = nums2[j] if j < len(nums2) else INF
            if i + j == mid:
                if next_nums1 <= next_nums2:
                    ans += next_nums1
                else:
                    ans += next_nums2
                cnt -= 1
                if cnt == 0:
                    break
                if cnt == 1:
                    mid += 1
            else:
                if next_nums1 <= next_nums2:
                    i += 1
                else:
                    j += 1

        if sum_len % 2 == 0:
            ans = ans / 2
        return ans
