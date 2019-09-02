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
const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int N, K;
vector<int> h;
int dp[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  h.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  fill(dp, dp + 100001, INF);

  dp[0] = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 1; j <= K; j++) {
      if (i + j < N) {
        dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
      }
    }
  }

  cout << dp[N - 1] << endl;
  return 0;
}