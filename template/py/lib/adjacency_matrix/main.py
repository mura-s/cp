import collections
import math
import sys

# グラフの隣接行列での表現。 (蟻本参照)
# 辺があるかの判定: 定数時間
# メモリ: |V|^2
#
# 無向グラフの場合、 g[i][j] == g[j][i] となるように設定する。
# 有向グラフの場合、 i->jに向かう辺があるなら、g[i][j] == 1 となる。

MAX_V = 3
g = [[0] * MAX_V for _ in range(MAX_V)]

# 無向グラフ & 重みなし (https://qiita.com/ell/items/2a327fe021fb7dafe07a#%E5%85%A5%E5%8A%9B-to-%E9%9A%A3%E6%8E%A5%E8%A1%8C%E5%88%97)
g[0][1] = 1
g[1][0] = 1
g[0][2] = 1
g[2][0] = 1
print(g)
