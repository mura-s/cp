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

const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

int N, M;
vector<int> D, C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  D.resize(N);
  rep(i, N) { cin >> D[i]; }
  C.resize(M);
  rep(i, M) { cin >> C[i]; }

  int dp[M + 1][N + 1];
  rep(i, M + 1) { fill(dp[i], dp[i] + N + 1, INF); }
  dp[0][0] = 0;

  rep(i, M) {
    rep(j, N + 1) {
      if (dp[i][j] != INF) {
        if (j == N) {
          dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        } else {
          dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
          dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + D[j] * C[i]);
        }
      }
    }
  }

  cout << dp[M][N] << endl;
  return 0;
}
