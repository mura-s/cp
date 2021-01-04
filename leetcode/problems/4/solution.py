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
    # O(N+M) の解法
    # def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
    #     ans = 0.0
    #     sum_len = len(nums1) + len(nums2)
    #     mid = (sum_len - 1) // 2
    #     i = 0
    #     j = 0
    #     cnt = 2 if sum_len % 2 == 0 else 1
    #     while True:
    #         next_nums1 = nums1[i] if i < len(nums1) else INF
    #         next_nums2 = nums2[j] if j < len(nums2) else INF
    #         if i + j == mid:
    #             if next_nums1 <= next_nums2:
    #                 ans += next_nums1
    #             else:
    #                 ans += next_nums2
    #             cnt -= 1
    #             if cnt == 0:
    #                 break
    #             if cnt == 1:
    #                 mid += 1
    #         else:
    #             if next_nums1 <= next_nums2:
    #                 i += 1
    #             else:
    #                 j += 1

    #     if sum_len % 2 == 0:
    #         ans = ans / 2
    #     return ans

    # O(log(min(m,n))) の解法
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m

        imin, imax, half_len = 0, m, (m + n + 1) // 2
        while imin <= imax:
            i = (imin + imax) // 2
            j = half_len - i
            if j > 0 and i < m and nums2[j-1] > nums1[i]:
                imin = i + 1
            elif i > 0 and j < n and nums1[i-1] > nums2[j]:
                imax = i - 1
            else:
                if i == 0:
                    max_of_left = nums2[j-1]
                elif j == 0:
                    max_of_left = nums1[i-1]
                else:
                    max_of_left = max(nums1[i-1], nums2[j-1])

                if (m + n) % 2 == 1:
                    return max_of_left

                if i == m:
                    min_of_right = nums2[j]
                elif j == n:
                    min_of_right = nums1[i]
                else:
                    min_of_right = min(nums1[i], nums2[j])

                return (max_of_left + min_of_right) / 2.0
