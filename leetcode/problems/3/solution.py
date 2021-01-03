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
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        l = 0
        r = 0
        st = set()
        s_len = len(s)
        while r < s_len:
            while (r < s_len) and (not s[r] in st):
                st.add(s[r])
                r += 1
            ans = max(ans, r - l)
            if r == s_len:
                break
            while s[l] != s[r]:
                st.remove(s[l])
                l += 1
            st.remove(s[l])
            l += 1
        return ans
