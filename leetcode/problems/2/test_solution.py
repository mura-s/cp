import pytest
from typing import List
from solution import Solution, ListNode


def list_node(l: List[int]) -> ListNode:
    ln = ListNode(l[0])
    prev = ln
    for i in range(1, len(l)):
        cur = ListNode(l[i])
        prev.next = cur
        prev = cur
    return ln


def lis(ln: ListNode) -> List[int]:
    l = []
    while ln != None:
        l.append(ln.val)
        ln = ln.next
    return l


def test_ans1():
    l1 = list_node([2, 4, 3])
    l2 = list_node([5, 6, 4])
    out = [7, 0, 8]
    assert lis(Solution().addTwoNumbers(l1, l2)) == out


def test_ans2():
    l1 = list_node([0])
    l2 = list_node([0])
    out = [0]
    assert lis(Solution().addTwoNumbers(l1, l2)) == out


def test_ans3():
    l1 = list_node([9, 9, 9, 9, 9, 9, 9])
    l2 = list_node([9, 9, 9, 9])
    out = [8, 9, 9, 9, 0, 0, 0, 1]
    assert lis(Solution().addTwoNumbers(l1, l2)) == out
