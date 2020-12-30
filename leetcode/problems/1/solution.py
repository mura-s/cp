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
    # def twoSum(self, nums: List[int], target: int) -> List[int]:
    #     len_nums = len(nums)
    #     for i in range(0, len_nums):
    #         for j in range(i+1, len_nums):
    #             if nums[i] + nums[j] == target:
    #                 return [i, j]

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = collections.defaultdict(int)
        for i, n in enumerate(nums):
            complement = target - n
            if complement in d:
                return [d.get(complement), i]
            d[n] = i
