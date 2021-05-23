import pytest
from solution import Solution


def test_ans1():
    assert Solution().twoSum([2, 7, 11, 15], 9) == [0, 1]


def test_ans2():
    assert Solution().twoSum([3, 2, 4], 6) == [1, 2]


def test_ans3():
    assert Solution().twoSum([3, 3], 6) == [0, 1]
