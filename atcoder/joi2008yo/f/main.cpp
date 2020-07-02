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
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;
const int MAX_V = 101;

struct edge {
  int to, cost;
};
typedef pair<int, int> P; // firstは最短距離, secondは頂点の番号

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

// 負辺のない単一始点全点間最短路を求めるアルゴリズム。
// 蟻本参照
//
// 計算量: O(ElogV)
void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) {
      continue;
    }

    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> k;
  rep(i, k) {
    int op;
    cin >> op;
    if (op == 0) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      dijkstra(a);
      if (d[b] == INF) {
        cout << -1 << endl;
      } else {
        cout << d[b] << endl;
      }
    } else {
      int c, d, e;
      cin >> c >> d >> e;
      c--;
      d--;
      bool found = false;
      for (int j = 0; j < G[c].size(); j++) {
        if (G[c][j].to == d) {
          G[c][j].cost = min(G[c][j].cost, e);
          found = true;
          break;
        }
      }
      if (!found) {
        G[c].push_back(edge{d, e});
      }
      found = false;
      for (int j = 0; j < G[d].size(); j++) {
        if (G[d][j].to == c) {
          G[d][j].cost = min(G[d][j].cost, e);
          found = true;
          break;
        }
      }
      if (!found) {
        G[d].push_back(edge{c, e});
      }
    }
  }
  return 0;
}
