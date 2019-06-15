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
  for (ll pos = 0; pos < len; pos++) {
    for (ll sum = 0; sum < D; sum++) {
      for (ll sml = 0; sml <= 1; sml++) {
        if (dp[pos][sum][sml] == 0) {
          continue;
        }

        if (sml == 1) {
          ll lim = 10;
          for (int d = 0; d < lim; d++) {
            dp[pos + 1][(sum + d) % D][1] += dp[pos][sum][1];
            dp[pos + 1][(sum + d) % D][1] %= MOD;
          }
        } else {
          ll lim = N[pos] - '0';
          for (int d = 0; d < lim; d++) {
            dp[pos + 1][(sum + d) % D][1] += dp[pos][sum][0];
            dp[pos + 1][(sum + d) % D][1] %= MOD;
          }
          dp[pos + 1][(sum + lim) % D][0] += dp[pos][sum][0];
          dp[pos + 1][(sum + lim) % D][0] %= MOD;
        }
      }
    }
  }

  ll ans = (dp[len][0][0] + dp[len][0][1] - 1) % MOD; // 0の分を引く
  cout << ans << endl;
  return 0;
}