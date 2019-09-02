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

int N;
vector<int> h;
int dp[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  h.resize(N + 1, 0);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  fill(dp, dp + 100001, INF);

  dp[0] = 0;
  for (int i = 0; i < (N - 2); i++) {
    dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
    dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
  }
  dp[N - 1] = min(dp[N - 1], dp[N - 2] + abs(h[N - 2] - h[N - 1]));

  cout << dp[N - 1] << endl;
  return 0;
}