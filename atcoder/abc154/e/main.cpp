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
using namespace std;
typedef long long ll;
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

string N;
ll K;

ll dp[105][2][4];
// 0: ok, 1: ?

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;

  // 1桁目
  dp[0][0][0] = 1;
  dp[0][0][1] = N[0] - '0' - 1;
  dp[0][1][1] = 1;

  // 残りの桁
  for (ll i = 1; i < N.size(); i++) {
    // 0
    dp[i][0][0] += dp[i - 1][0][0];
    dp[i][0][1] += dp[i - 1][0][0] * 9;

    dp[i][0][1] += dp[i - 1][0][1];
    dp[i][0][2] += dp[i - 1][0][1] * 9;

    dp[i][0][2] += dp[i - 1][0][2];
    dp[i][0][3] += dp[i - 1][0][2] * 9;

    dp[i][0][3] += dp[i - 1][0][3];

    // 1
    if (N[i] == '0') {
      dp[i][1][1] += dp[i - 1][1][1];
      dp[i][1][2] += dp[i - 1][1][2];
      dp[i][1][3] += dp[i - 1][1][3];
    } else {
      dp[i][1][2] += dp[i - 1][1][1];
      dp[i][0][2] += dp[i - 1][1][1] * (N[i] - '0' - 1);
      dp[i][0][1] += dp[i - 1][1][1];

      dp[i][1][3] += dp[i - 1][1][2];
      dp[i][0][3] += dp[i - 1][1][2] * (N[i] - '0' - 1);
      dp[i][0][2] += dp[i - 1][1][2];

      dp[i][0][3] += dp[i - 1][1][3];
    }
  }

  ll ans = dp[N.size() - 1][0][K] + dp[N.size() - 1][1][K];
  cout << ans << endl;
  return 0;
}
