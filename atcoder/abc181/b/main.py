import sys

# INF = (1 << 30) - 1
# LL_INF = (1 << 62) - 1
# MOD = 10**9 + 7

n = int(input())
# a = list(map(int, input().split()))

ans = 0
for _ in range(n):
    a, b = map(int, input().split())
    m = b - a + 1
    ans += (a + b) * m // 2

print(ans)
