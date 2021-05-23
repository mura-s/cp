import pytest
from solution import Solution


def test_ans1():
    assert Solution().longestPalindrome("babad") == "bab"


def test_ans2():
    assert Solution().longestPalindrome("cbbd") == "bb"


def test_ans3():
    assert Solution().longestPalindrome("a") == "a"


def test_ans4():
    assert Solution().longestPalindrome("ac") == "a"
