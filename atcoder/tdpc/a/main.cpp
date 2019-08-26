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

int N;
bool dp[101][10001];
vector<int> p;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  p.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  dp[0][0] = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10001; j++) {
      if (dp[i][j]) {
        dp[i + 1][j] = true;
        dp[i + 1][j + p[i]] = true;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 10001; i++) {
    if (dp[N][i]) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}