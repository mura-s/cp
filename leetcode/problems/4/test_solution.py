import pytest
from solution import Solution


def test_ans1():
    assert Solution().findMedianSortedArrays([1, 3], [2]) == 2.00000


def test_ans2():
    assert Solution().findMedianSortedArrays([1, 2], [3, 4]) == 2.50000


def test_ans3():
    assert Solution().findMedianSortedArrays([0, 0], [0, 0]) == 0.00000


def test_ans4():
    assert Solution().findMedianSortedArrays([], [1]) == 1.00000


def test_ans5():
    assert Solution().findMedianSortedArrays([2], []) == 2.00000
