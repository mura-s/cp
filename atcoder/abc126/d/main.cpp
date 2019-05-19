#include <algorithm>
#include <climits>
#include <cmath>
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
// const ll MOD = 1000000007;
// const int INF = 2000000000;

// グラフの隣接リストでの表現。 (蟻本参照)
// 辺があるかの判定: 最悪|V|
// メモリ: |V| + |E|

const int MAX_V = 100000;

struct edge {
  int to, cost;
};
vector<edge> g[MAX_V];

int N;

// 0: even
// 1: odd
vector<int> ans;
vector<bool> visit;

void dfs(int v, int cost) {
  if (visit[v]) {
    return;
  }
  visit[v] = true;
  if (cost % 2 == 0) {
    ans[v] = 0;
  } else {
    ans[v] = 1;
  }

  for (int i = 0; i < g[v].size(); i++) {
    dfs(g[v][i].to, cost + g[v][i].cost);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int ui, vi, wi;
    cin >> ui >> vi >> wi;
    ui--;
    vi--;
    g[ui].push_back(edge{vi, wi});
    g[vi].push_back(edge{ui, wi});
  }

  visit.resize(N, false);
  ans.resize(N, 0);
  dfs(0, 0);

  for (int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}