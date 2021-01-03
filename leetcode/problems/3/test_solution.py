from unittest import TestCase
from solution import Solution


class TestSolution(TestCase):
    def test_ans1(self):
        self.assertEqual(Solution().lengthOfLongestSubstring("abcabcbb"), 3)

    def test_ans2(self):
        self.assertEqual(Solution().lengthOfLongestSubstring("bbbbb"), 1)

    def test_ans3(self):
        self.assertEqual(Solution().lengthOfLongestSubstring("pwwkew"), 3)

    def test_ans4(self):
        self.assertEqual(Solution().lengthOfLongestSubstring(""), 0)

    def test_ans5(self):
        self.assertEqual(Solution().lengthOfLongestSubstring("abcbdefgh"), 7)
