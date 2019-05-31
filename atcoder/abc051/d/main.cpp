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
const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

const int MAX_V = 101;

int d[MAX_V][MAX_V];
int V, E;
map<pair<int, int>, bool> mp;
vector<int> a, b;

void warshall_floyd() {
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (d[i][k] == INF || d[k][j] == INF) {
          continue;
        }
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
          mp[make_pair(i, j)] = false;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> E;
  a.resize(E);
  b.resize(E);
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (i == j) {
        d[i][j] = 0;
      } else {
        d[i][j] = INF;
      }
    }
  }
  for (int i = 0; i < E; i++) {
    int ai, bi, ci;
    cin >> ai >> bi >> ci;
    ai--;
    bi--;
    d[ai][bi] = ci;
    d[bi][ai] = ci;
    a[i] = ai;
    b[i] = bi;
    mp[make_pair(ai, bi)] = true;
    mp[make_pair(bi, ai)] = true;
  }

  warshall_floyd();
  int ans = 0;
  for (int i = 0; i < E; i++) {
    if (!mp[make_pair(a[i], b[i])] && !mp[make_pair(b[i], a[i])]) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}