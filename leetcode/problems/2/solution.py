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


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        s = l1.val + l2.val
        ln = ListNode(s % 10)
        c = s // 10
        l1 = l1.next
        l2 = l2.next
        prev = ln
        while True:
            if l1 == None and l2 == None:
                break
            s = c
            if l1 != None:
                s += l1.val
                l1 = l1.next
            if l2 != None:
                s += l2.val
                l2 = l2.next
            cur = ListNode(s % 10)
            c = s // 10
            prev.next = cur
            prev = cur
        if c != 0:
            cur = ListNode(c)
            prev.next = cur
        return ln
