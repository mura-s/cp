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

const int MAX_V = 301;

int d[MAX_V][MAX_V];
int V, E;

// 隣接行列で表されるグラフの全点間最短路を求めるアルゴリズム。
// 負辺があっても動作する。負閉路が存在する場合はそれも検出する。
// https://ei1333.github.io/luzhiled/snippets/graph/warshall-floyd.html
//
// 計算量: O(V^3)
void warshall_floyd() {
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (d[i][k] == INF || d[k][j] == INF) {
          continue;
        }
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> E;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (i == j) {
        d[i][j] = 0;
      } else {
        d[i][j] = INF;
      }
    }
  }
  rep(i, E) {
    int a, b, t;
    cin >> a >> b >> t;
    a--;
    b--;
    d[a][b] = t;
    d[b][a] = t;
  }
  warshall_floyd();

  int ans = INF;
  rep(i, V) {
    int m = 0;
    rep(j, V) { m = max(m, d[i][j]); }
    ans = min(ans, m);
  }
  cout << ans << endl;
  return 0;
}
