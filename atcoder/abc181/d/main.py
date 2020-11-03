import collections
import math
import sys

# INF = (1 << 30) - 1
# LL_INF = (1 << 62) - 1
# MOD = 10**9 + 7

s = input()
if len(s) <= 2:
    rev = int(s[::-1])
    if int(s) % 8 == 0 or rev % 8 == 0:
        print('Yes')
    else:
        print('No')
    exit()

# len(s) > 2
cnt = collections.Counter(s)
for n in range(104, 1000, 8):
    n_arr = [0] * 10
    for c in str(n):
        n_arr[int(c)] += 1
    flag = True
    for i, v in enumerate(n_arr):
        if cnt[str(i)] < v:
            flag = False
            break
    if flag:
        print('Yes')
        exit()

print('No')
