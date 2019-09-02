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
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int N;
int dp[100001][3];
vector<tuple<int, int, int>> abc;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  abc.resize(N);
  for (int i = 0; i < N; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    abc[i] = make_tuple(a, b, c);
  }

  for (int i = 0; i < N; i++) {
    dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + get<1>(abc[i]));
    dp[i + 1][2] = max(dp[i + 1][2], dp[i][0] + get<2>(abc[i]));

    dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + get<2>(abc[i]));
    dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + get<0>(abc[i]));

    dp[i + 1][0] = max(dp[i + 1][0], dp[i][2] + get<0>(abc[i]));
    dp[i + 1][1] = max(dp[i + 1][1], dp[i][2] + get<1>(abc[i]));
  }

  int ans = max(dp[N][0], dp[N][1]);
  cout << max(ans, dp[N][2]) << endl;
  return 0;
}