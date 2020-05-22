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
const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

int H, W;
int s[101][101];
int dp[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      char sij;
      cin >> sij;
      if (sij == '.') {
        s[i][j] = 0;
      } else {
        s[i][j] = 1;
      }
    }
  }

  fill(dp[0], dp[101], INF);
  if (s[1][1] == 0) {
    dp[1][1] = 0;
  } else {
    dp[1][1] = 1;
  }

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (s[i][j] == 0) {
        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      } else {
        if (s[i][j - 1] == 0) {
          dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        } else {
          dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }

        if (s[i - 1][j] == 0) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        } else {
          dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
      }
    }
  }

  cout << dp[H][W] << endl;
  return 0;
}
