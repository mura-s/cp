import collections
import math
import sys

# グラフの隣接リストでの表現。 (蟻本参照)
# 辺があるかの判定: 最悪|V|
# メモリ: |V| + |E|

MAX_V = 3

# 辺に属性がない場合
g = [[] for _ in range(MAX_V)]

g[0].append(1)
g[0].append(2)
g[1].append(2)
for i in range(MAX_V):
    print(g[i])

# 辺に属性がある場合


class Edge:
    def __init__(self, to: int, cost: int):
        self._to = to
        self._cost = cost

    def to(self):
        return self._to

    def cost(self):
        return self._cost


g = [[] for _ in range(MAX_V)]

g[0].append(Edge(1, 1))
g[0].append(Edge(2, 2))
g[1].append(Edge(2, 3))
for i in range(MAX_V):
    for v in g[i]:
        print('{}: {} {}'.format(i, v.to(), v.cost()))
