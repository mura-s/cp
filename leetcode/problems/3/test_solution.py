import pytest
from solution import Solution


def test_ans1():
    assert Solution().lengthOfLongestSubstring("abcabcbb") == 3


def test_ans2():
    assert Solution().lengthOfLongestSubstring("bbbbb") == 1


def test_ans3():
    assert Solution().lengthOfLongestSubstring("pwwkew") == 3


def test_ans4():
    assert Solution().lengthOfLongestSubstring("") == 0


def test_ans5():
    assert Solution().lengthOfLongestSubstring("abcbdefgh") == 7
