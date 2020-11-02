import sys

# INF = (1 << 30) - 1
# LL_INF = (1 << 62) - 1
# MOD = 10**9 + 7

n = int(input())
x = [0] * n
y = [0] * n
for i in range(n):
    xi, yi = map(int, input().split())
    x[i] = xi
    y[i] = yi

flag = False
for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            dx1 = x[i] - x[j]
            dy1 = y[i] - y[j]
            dx2 = x[j] - x[k]
            dy2 = y[j] - y[k]
            if dx1 == 0 and dx2 == 0:
                flag = True
                break
            elif dx1 == 0 or dx2 == 0:
                continue

            m1 = dy1 / dx1
            m2 = dy2 / dx2
            if m1 == m2:
                flag = True
                break

if flag:
    print('Yes')
else:
    print('No')
