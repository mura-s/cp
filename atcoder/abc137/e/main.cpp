#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
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

const int MAX_V = 2501;
const int MAX_E = 5001;

struct edge {
  int from, to, cost;
};

// 辺
edge es[MAX_E];
// 最短距離
int d[MAX_V];
int V, E;
int P;

vector<int> to[2501];
vector<int> rto[2501];
bool ok[2501];
bool rok[2501];

void dfs(int s) {
  if (ok[s]) {
    return;
  }
  ok[s] = true;
  for (int i = 0; i < to[s].size(); i++) {
    dfs(to[s][i]);
  }
}

void rdfs(int s) {
  if (rok[s]) {
    return;
  }
  rok[s] = true;
  for (int i = 0; i < rto[s].size(); i++) {
    rdfs(rto[s][i]);
  }
}

bool bellman_ford(int s) {
  fill(d, d + V, INF);
  d[s] = 0;

  for (int i = 0; i < V - 1; i++) {
    for (int j = 0; j < E; j++) {
      edge e = es[j];
      if (d[e.from] == INF) {
        continue;
      }
      // 経路チェック
      if (ok[e.from] && rok[e.from]) {
        d[e.to] = min(d[e.to], d[e.from] + e.cost);
      }
    }
  }

  for (int j = 0; j < E; j++) {
    edge e = es[j];
    if (d[e.from] == INF) {
      continue;
    }
    if (d[e.from] + e.cost < d[e.to]) {
      // 経路チェック
      if (ok[e.from] && rok[e.from]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> E >> P;
  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    es[i] = edge{a, b, P - c};
    to[a].push_back(b);
    rto[b].push_back(a);
  }

  // 0からの経路があるか
  dfs(0);
  // V-1への経路があるか
  rdfs(V - 1);

  bool flag = bellman_ford(0);
  if (!flag) {
    cout << -1 << endl;
    return 0;
  }

  int ans = max(-d[V - 1], 0);
  cout << ans << endl;
  return 0;
}