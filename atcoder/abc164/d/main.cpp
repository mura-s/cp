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

const ll NUM = 2019;

string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;

  ll ans = 0;
  vector<ll> dp(2019, 0);
  for (int i = 0; i < S.size(); i++) {
    vector<ll> next_dp(2019, 0);
    ll n = S[i] - '0';
    next_dp[n] = 1;
    for (int j = 0; j < 2019; j++) {
      if (dp[j] > 0) {
        next_dp[(j * 10 + n) % NUM] += dp[j];
      }
    }
    dp = next_dp;
    ans += dp[0];
  }

  cout << ans << endl;
  return 0;
}