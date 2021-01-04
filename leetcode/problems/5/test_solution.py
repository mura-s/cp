from unittest import TestCase
from solution import Solution


class TestSolution(TestCase):
    def test_ans1(self):
        self.assertEqual(Solution().longestPalindrome("babad"), "bab")

    def test_ans2(self):
        self.assertEqual(Solution().longestPalindrome("cbbd"), "bb")

    def test_ans3(self):
        self.assertEqual(Solution().longestPalindrome("a"), "a")

    def test_ans4(self):
        self.assertEqual(Solution().longestPalindrome("ac"), "a")
