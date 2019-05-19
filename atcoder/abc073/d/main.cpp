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
const int INF = 2000000000;

const int MAX_V = 200;

int d[MAX_V][MAX_V];
int V, E;

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

int R;
vector<int> r;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> E >> R;
  r.resize(R);
  for (int i = 0; i < R; i++) {
    int ri;
    cin >> ri;
    ri--;
    r[i] = ri;
  }
  sort(r.begin(), r.end());

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
  }
  warshall_floyd();

  int ans = INF;
  do {
    int sum = 0;
    bool flag = true;
    for (int i = 1; i < R; i++) {
      if (d[r[i - 1]][r[i]] == INF) {
        flag = false;
        break;
      }
      sum += d[r[i - 1]][r[i]];
    }

    if (flag) {
      ans = min(ans, sum);
    }
  } while (next_permutation(r.begin(), r.end()));

  cout << ans << endl;
  return 0;
}