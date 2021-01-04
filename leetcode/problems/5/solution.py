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
# INF = (1 << 30) - 1
# LL_INF = (1 << 62) - 1
# MOD = 10**9 + 7


class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = s[0]
        n = len(s)
        for i in range(n):
            # odd
            left, right = i, i
            while left - 1 >= 0 and right + 1 < n and s[left-1] == s[right+1]:
                left -= 1
                right += 1
            if len(ans) < right + 1 - left:
                ans = s[left:right+1]

            # even
            left, right = i, i + 1
            if right >= n or s[left] != s[right]:
                continue
            while left - 1 >= 0 and right + 1 < n and s[left-1] == s[right+1]:
                left -= 1
                right += 1
            if len(ans) < right + 1 - left:
                ans = s[left:right+1]

        return ans
