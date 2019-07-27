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

string S;
ll dp[100001][13];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;

  dp[0][0] = 1;
  for (int i = 0; i < S.size(); i++) {
    int c = 0;
    if (S[i] == '?') {
      c = -1;
    } else {
      c = S[i] - '0';
    }

    for (int j = 0; j < 10; j++) {
      if (c == -1 || c == j) {
        for (int k = 0; k < 13; k++) {
          dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
          dp[i + 1][(k * 10 + j) % 13] %= MOD;
        }
      }
    }
  }

  cout << dp[S.size()][5] << endl;
  return 0;
}