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

int H, N;
vector<int> A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> N;
  A.resize(N);
  B.resize(N);
  for (int i = 0; i < N; i++) {
    int ai, bi;
    cin >> ai >> bi;
    A[i] = ai;
    B[i] = bi;
  }

  vector<int> dp(10001, INF);
  dp[0] = 0;
  for (int i = 0; i < H; i++) {
    if (dp[i] == INF) {
      continue;
    }
    for (int j = 0; j < N; j++) {
      int h = min(H, i + A[j]);
      dp[h] = min(dp[h], dp[i] + B[j]);
    }
  }

  int ans = dp[H];
  cout << ans << endl;
  return 0;
}
