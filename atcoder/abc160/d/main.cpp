#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

const int MAX_V = 2001;

struct edge {
  int to, cost;
};
typedef pair<int, int> P; // firstは最短距離, secondは頂点の番号

int V;
vector<edge> G[MAX_V];
int d[MAX_V][MAX_V];

// 負辺のない単一始点全点間最短路を求めるアルゴリズム。
// 蟻本参照
//
// 計算量: O(ElogV)
void dijkstra(int s, int idx) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d[idx], d[idx] + V, INF);
  d[idx][s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[idx][v] < p.first) {
      continue;
    }

    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[idx][e.to] > d[idx][v] + e.cost) {
        d[idx][e.to] = d[idx][v] + e.cost;
        que.push(P(d[idx][e.to], e.to));
      }
    }
  }
}

int X, Y;
// vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> X >> Y;
  X--;
  Y--;
  for (int i = 0; i < V - 1; i++) {
    G[i].push_back(edge{i + 1, 1});
    G[i + 1].push_back(edge{i, 1});
  }
  G[X].push_back(edge{Y, 1});
  G[Y].push_back(edge{X, 1});

  for (int i = 0; i < V; i++) {
    dijkstra(i, i);
  }

  vector<int> ans(V, 0);
  for (int i = 0; i < V; i++) {
    for (int j = i + 1; j < V; j++) {
      ans[d[i][j]]++;
    }
  }

  for (int i = 1; i < V; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
