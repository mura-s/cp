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

int A, B;
vector<int> a, b;
int dp[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B;
  a.resize(A);
  for (int i = 0; i < A; i++) {
    cin >> a[i];
  }
  b.resize(B);
  for (int i = 0; i < B; i++) {
    cin >> b[i];
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int last = (A + B) % 2;
  for (int i = 0; i <= A; i++) {
    for (int j = 0; j <= B; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      if ((i + j) % 2 == last) {
        if (i == 0) {
          dp[i][j] = dp[i][j - 1] + b[j - 1];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j] + a[i - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j] + a[i - 1], dp[i][j - 1] + b[j - 1]);
        }
      } else {
        if (i == 0) {
          dp[i][j] = dp[i][j - 1];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
  }

  cout << dp[A][B] << endl;
  return 0;
}
