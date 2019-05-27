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

const int MAX = 401;

int N, Ma, Mb;
int dp[MAX][MAX];
vector<int> a, b, c;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Ma >> Mb;
  a.resize(N);
  b.resize(N);
  c.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  fill(dp[0], dp[MAX], INF);
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = MAX - 1; j >= 0; j--) {
      for (int k = MAX - 1; k >= 0; k--) {
        if (dp[j][k] != INF) {
          dp[j + a[i]][k + b[i]] = min(dp[j + a[i]][k + b[i]], dp[j][k] + c[i]);
        }
      }
    }
  }

  int ans = INF;
  for (int j = 1; j < MAX; j++) {
    for (int k = 1; k < MAX; k++) {
      if (dp[j][k] == INF) {
        continue;
      }
      if (j * Mb == k * Ma) {
        ans = min(ans, dp[j][k]);
      }
    }
  }

  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}