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

const int MAX_V = 100000;

struct edge {
  int to;
  ll cost;
};
vector<edge> g[MAX_V];

vector<ll> costs;

int N;
int Q, K;

void dfs(int v, ll c) {
  if (costs[v] != -1) {
    return;
  }
  costs[v] = c;

  for (int i = 0; i < g[v].size(); i++) {
    dfs(g[v][i].to, c + g[v][i].cost);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int ai, bi;
    ll ci;
    cin >> ai >> bi >> ci;
    ai--;
    bi--;
    g[ai].push_back(edge{bi, ci});
    g[bi].push_back(edge{ai, ci});
  }
  costs.resize(N, -1);

  cin >> Q >> K;
  K--;
  dfs(K, 0);

  for (int i = 0; i < Q; i++) {
    int xi, yi;
    cin >> xi >> yi;
    xi--;
    yi--;
    cout << costs[xi] + costs[yi] << endl;
  }
  return 0;
}