import sys
import math

# INF = (1 << 30) - 1
# LL_INF = (1 << 62) - 1
# MOD = 10**9 + 7


def lcm(x, y):
    return x // math.gcd(x, y) * y


a = 6
b = 4
print(math.gcd(a, b))
print(lcm(a, b))
