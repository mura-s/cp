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

int K;
int N;
vector<int> R;

double elo_rating(double rp, double rq) { return 1 / (1 + pow(10, (rq - rp) / 400)); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> K;
  N = pow(2, K);
  R.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> R[i];
  }
  double dp[K + 1][N];
  fill(dp[0], dp[K + 1], 0.0);
  for (int i = 0; i < N; i++) {
    dp[0][i] = 1.0;
  }

  for (int i = 1; i <= K; i++) {
    for (int j = 0; j < N; j++) {
      int num = pow(2, i - 1);
      if ((j % (2 * num)) != 0) {
        continue;
      }
      for (int m = j; m < j + num; m++) {
        for (int n = j + num; n < j + 2 * num; n++) {
          dp[i][m] += (dp[i - 1][m] * dp[i - 1][n] * elo_rating(R[m], R[n]));
          dp[i][n] += (dp[i - 1][m] * dp[i - 1][n] * elo_rating(R[n], R[m]));
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << fixed << setprecision(9) << dp[K][i] << endl;
  }
  return 0;
}