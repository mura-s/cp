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

int N, K;
ll dp[1000001][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;

  dp[0][0] = 1;
  dp[1][1] = 1;
  for (int i = 2; i <= N; i++) {
    dp[i][0] += (dp[i - 1][1] + dp[i - 1][0]);
    dp[i][0] %= MOD;

    dp[i][1] += (dp[i - 1][1] + dp[i - 1][0]);
    if (i - K >= 0) {
      dp[i][1] = (dp[i][1] - dp[i - K][0] + MOD) % MOD;
    }
    dp[i][1] %= MOD;
  }

  cout << dp[N][1] << endl;
  return 0;
}