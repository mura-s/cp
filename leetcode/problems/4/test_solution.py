from unittest import TestCase
from solution import Solution


class TestSolution(TestCase):
    def test_ans1(self):
        self.assertEqual(
            Solution().findMedianSortedArrays([1, 3], [2]), 2.00000)

    def test_ans2(self):
        self.assertEqual(Solution().findMedianSortedArrays(
            [1, 2], [3, 4]), 2.50000)

    def test_ans3(self):
        self.assertEqual(Solution().findMedianSortedArrays(
            [0, 0], [0, 0]), 0.00000)

    def test_ans4(self):
        self.assertEqual(Solution().findMedianSortedArrays([], [1]), 1.00000)

    def test_ans5(self):
        self.assertEqual(Solution().findMedianSortedArrays([2], []), 2.00000)
