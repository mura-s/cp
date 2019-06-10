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

string L;
// 0: 未確定, 1: 確定
ll dp[100002][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> L;

  dp[0][0] = 1;
  dp[0][1] = 0;
  for (ll i = 0; i < L.size(); i++) {
    if (L[i] == '0') {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1] * 3 % MOD;
    } else {
      dp[i + 1][0] = dp[i][0] * 2 % MOD;
      dp[i + 1][1] = (dp[i][0] + dp[i][1] * 3) % MOD;
    }
  }

  cout << (dp[L.size()][0] + dp[L.size()][1]) % MOD << endl;
  return 0;
}