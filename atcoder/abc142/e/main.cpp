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
const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

ll N, M;
vector<ll> a, b;
vector<ll> c;

const int MAX = 1 << 12;
ll dp[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  a.resize(M);
  b.resize(M);
  c.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    for (int j = 0; j < b[i]; j++) {
      int ci;
      cin >> ci;
      c[i] |= (1 << (ci - 1));
    }
  }

  fill(dp, dp + MAX, LL_INF);
  dp[0] = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < (1 << N); j++) {
      ll next = j | c[i];
      dp[next] = min(dp[next], dp[j] + a[i]);
    }
  }

  int idx = (1 << N) - 1;
  if (dp[idx] == LL_INF) {
    cout << -1 << endl;
  } else {
    cout << dp[idx] << endl;
  }

  return 0;
}