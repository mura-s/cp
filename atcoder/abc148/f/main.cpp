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
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

const int INF = (1 << 30) - 1;
const int MAX_V = 100001;

struct edge {
  int to, cost;
};
typedef pair<int, int> P; // firstは最短距離, secondは頂点の番号

int V, E;
vector<edge> G[MAX_V];
int du[MAX_V];

void dijkstra_u(int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(du, du + V, INF);
  du[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (du[v] < p.first) {
      continue;
    }

    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (du[e.to] > du[v] + e.cost) {
        du[e.to] = du[v] + e.cost;
        que.push(P(du[e.to], e.to));
      }
    }
  }
}

int dv[MAX_V];

void dijkstra_v(int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(dv, dv + V, INF);
  dv[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (dv[v] < p.first) {
      continue;
    }

    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (dv[e.to] > dv[v] + e.cost) {
        dv[e.to] = dv[v] + e.cost;
        que.push(P(dv[e.to], e.to));
      }
    }
  }
}

int u, v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> u >> v;
  u--;
  v--;
  E = V - 1;
  for (int i = 0; i < E; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(edge{b, 1});
    G[b].push_back(edge{a, 1});
  }

  dijkstra_u(u);
  dijkstra_v(v);
  int ans = 0;
  for (int i = 0; i < V; i++) {
    if (du[i] < dv[i]) {
      ans = max(ans, dv[i] - 1);
    }
  }

  cout << ans << endl;
  return 0;
}