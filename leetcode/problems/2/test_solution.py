from unittest import TestCase
from typing import List
from solution import Solution, ListNode


class TestSolution(TestCase):
    def list_node(self, l: List[int]) -> ListNode:
        ln = ListNode(l[0])
        prev = ln
        for i in range(1, len(l)):
            cur = ListNode(l[i])
            prev.next = cur
            prev = cur
        return ln

    def lis(self, ln: ListNode) -> List[int]:
        l = []
        while ln != None:
            l.append(ln.val)
            ln = ln.next
        return l

    def test_ans1(self):
        l1 = self.list_node([2, 4, 3])
        l2 = self.list_node([5, 6, 4])
        out = [7, 0, 8]
        self.assertEqual(self.lis(Solution().addTwoNumbers(l1, l2)), out)

    def test_ans2(self):
        l1 = self.list_node([0])
        l2 = self.list_node([0])
        out = [0]
        self.assertEqual(self.lis(Solution().addTwoNumbers(l1, l2)), out)

    def test_ans3(self):
        l1 = self.list_node([9, 9, 9, 9, 9, 9, 9])
        l2 = self.list_node([9, 9, 9, 9])
        out = [8, 9, 9, 9, 0, 0, 0, 1]
        self.assertEqual(self.lis(Solution().addTwoNumbers(l1, l2)), out)
