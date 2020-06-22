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
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

long N;
vector<long> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  rep(i, N) { cin >> A[i]; }

  long ans = A[N - 1];
  long dp[N][21];
  rep(i, N) { fill(dp[i], dp[i] + 21, 0); }
  dp[1][A[0]] = 1;

  for (int i = 1; i < N - 1; i++) {
    rep(j, 21) {
      if (dp[i][j] == 0) {
        continue;
      }
      if (j - A[i] >= 0) {
        dp[i + 1][j - A[i]] += dp[i][j];
      }
      if (j + A[i] <= 20) {
        dp[i + 1][j + A[i]] += dp[i][j];
      }
    }
  }

  cout << dp[N - 1][ans] << endl;
  return 0;
}
