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
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
const ll MOD = 10000;
// const double PI = M_PI;

ll N, K;
map<ll, ll> mp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  rep(i, K) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    mp[a] = b;
  }

  ll dp[N][3][3];
  rep(i, N) {
    rep(j, 3) { fill(dp[i][j], dp[i][j] + 3, 0); }
  }
  if (mp.find(0) != mp.end() && mp.find(1) != mp.end()) {
    dp[1][mp[0]][mp[1]] = 1;
  } else if (mp.find(0) != mp.end()) {
    dp[1][mp[0]][0] = 1;
    dp[1][mp[0]][1] = 1;
    dp[1][mp[0]][2] = 1;
  } else if (mp.find(1) != mp.end()) {
    dp[1][0][mp[1]] = 1;
    dp[1][1][mp[1]] = 1;
    dp[1][2][mp[1]] = 1;
  } else {
    rep(i, 3) {
      rep(j, 3) { dp[1][i][j] = 1; }
    }
  }

  for (int k = 2; k < N; k++) {
    if (mp.find(k) != mp.end()) {
      rep(i, 3) {
        rep(j, 3) {
          ll v = mp[k];
          if (i != v || j != v) {
            dp[k][j][v] += dp[k - 1][i][j];
            dp[k][j][v] %= MOD;
          }
        }
      }
    } else {
      rep(i, 3) {
        rep(j, 3) {
          if (i == j) {
            dp[k][j][(j + 1) % 3] += dp[k - 1][i][j];
            dp[k][j][(j + 1) % 3] %= MOD;
            dp[k][j][(j + 2) % 3] += dp[k - 1][i][j];
            dp[k][j][(j + 2) % 3] %= MOD;
          } else {
            dp[k][j][0] += dp[k - 1][i][j];
            dp[k][j][0] %= MOD;
            dp[k][j][1] += dp[k - 1][i][j];
            dp[k][j][1] %= MOD;
            dp[k][j][2] += dp[k - 1][i][j];
            dp[k][j][2] %= MOD;
          }
        }
      }
    }
  }

  ll ans = 0;
  rep(i, 3) {
    rep(j, 3) {
      ans += dp[N - 1][i][j];
      ans %= MOD;
    }
  }
  cout << ans % MOD << endl;
  return 0;
}
