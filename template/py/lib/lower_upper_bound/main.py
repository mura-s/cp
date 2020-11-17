import bisect
import collections
import itertools
import math
import sys
from copy import deepcopy
from decimal import Decimal
from heapq import heappop, heappush
from operator import itemgetter

vec = [1, 3, 3, 4, 5]


def check(idx: int, v: int):
    # implement check if needed
    return vec[idx] >= v


def binary_search(size: int, v: int):
    '''自前のlower_bound的な実装
    '''
    left = 0
    right = size
    # always satisfied with the check.
    while left < right:
        mid = (left + right) // 2
        if check(mid, v):
            right = mid
        else:
            left = mid + 1
    return right


# 標準ライブラリ使用
# ref: https://qiita.com/Kentaro_okumura/items/5b95b767a2e691cd5482#bisectbisect_left-bisectbisect_right-bisectbisect
print(bisect.bisect_left(vec, 3))
print(bisect.bisect_right(vec, 3))


# 自前実装
print(binary_search(len(vec), 3))
