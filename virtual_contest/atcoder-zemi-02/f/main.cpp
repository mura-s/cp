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

const int MAX_V = 101;
vector<int> g[MAX_V];
vector<int> h;
bool visit[101];

int n, x;

int dfs(int v) {
  if (visit[v]) {
    return 0;
  }
  visit[v] = true;
  int cost = h[v] * 2;
  for (int i = 0; i < g[v].size(); i++) {
    int next_v = g[v][i];
    cost += dfs(next_v);
  }
  if (h[v] == 0 && cost > 0) {
    cost += 2;
  }
  return cost;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x;
  x--;
  h.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int ai, bi;
    cin >> ai >> bi;
    ai--;
    bi--;
    g[ai].push_back(bi);
    g[bi].push_back(ai);
  }

  int ans = max(dfs(x) - 2, 0);
  cout << ans << endl;
  return 0;
}