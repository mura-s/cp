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
// const int INF = (1 << 30) - 1;
// const ll L_INF = (1LL << 62) - 1;
const ll MOD = 998244353;
// const double PI = M_PI;

ll N, S;
vector<ll> A;

ll dp[3001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> S;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    ll tmp;
    cin >> tmp;
    A[i] = tmp;
  }

  dp[0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = S; j >= 0; j--) {
      if (j + A[i] <= S) {
        dp[j + A[i]] += dp[j];
        dp[j + A[i]] %= MOD;
      }
    }
  }

  cout << dp[S] % MOD << endl;
  return 0;
}
