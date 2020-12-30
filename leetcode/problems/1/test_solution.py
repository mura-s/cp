from unittest import TestCase
from solution import Solution


class TestSolution(TestCase):
    def test_ans1(self):
        self.assertEqual(Solution().twoSum([2, 7, 11, 15], 9), [0, 1])

    def test_ans2(self):
        self.assertEqual(Solution().twoSum([3, 2, 4], 6), [1, 2])

    def test_ans3(self):
        self.assertEqual(Solution().twoSum([3, 3], 6), [0, 1])
