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
const ll MOD = 1e9 + 7;

ll D;
string N;
// dp[pos][sum][sml]
// sml==0: 制限あり, sml==1: 制限なし
ll dp[10001][101][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> D >> N;
  ll len = N.size();
  dp[0][0][0] = 1;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < D; j++) {
      for (int k = 0; k <= 1; k++) {
        if (dp[i][j][k] == 0) {
          continue;
        }

        if (k == 1) {
          for (int d = 0; d < 10; d++) {
            dp[i + 1][(j + d) % D][1] += dp[i][j][1];
            dp[i + 1][(j + d) % D][1] %= MOD;
          }
        } else {
          int lim = N[i] - '0';
          for (int d = 0; d < lim; d++) {
            dp[i + 1][(j + d) % D][1] += dp[i][j][0];
            dp[i + 1][(j + d) % D][1] %= MOD;
          }
          dp[i + 1][(j + lim) % D][0] += dp[i][j][0];
          dp[i + 1][(j + lim) % D][0] %= MOD;
        }
      }
    }
  }

  ll ans = (dp[len][0][0] + dp[len][0][1] - 1) % MOD; // 0の分を引く
  cout << ans << endl;
  return 0;
}