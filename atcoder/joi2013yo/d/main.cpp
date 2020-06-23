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

int D, N;
vector<int> T;
vector<int> A, B, C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> D >> N;
  T.resize(D);
  rep(i, D) { cin >> T[i]; }
  A.resize(N);
  B.resize(N);
  C.resize(N);
  rep(i, N) { cin >> A[i] >> B[i] >> C[i]; }

  int dp[D][101];
  rep(i, D) { fill(dp[i], dp[i] + 101, -1); }
  rep(i, N) {
    if (A[i] <= T[0] && T[0] <= B[i]) {
      dp[0][C[i]] = 0;
    }
  }

  rep(i, D - 1) {
    rep(j, 101) {
      rep(k, N) {
        if (dp[i][j] != -1 && A[k] <= T[i + 1] && T[i + 1] <= B[k]) {
          dp[i + 1][C[k]] = max(dp[i + 1][C[k]], dp[i][j] + abs(j - C[k]));
        }
      }
    }
  }

  int ans = 0;
  rep(i, 101) {
    if (dp[D - 1][i] != -1) {
      ans = max(ans, dp[D - 1][i]);
    }
  }
  cout << ans << endl;
  return 0;
}
