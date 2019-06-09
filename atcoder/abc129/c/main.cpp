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

ll N, M;
vector<ll> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  a.resize(M);
  for (ll i = 0; i < M; i++) {
    cin >> a[i];
  }

  for (ll i = 0; i < M - 1; i++) {
    if (a[i + 1] - a[i] == 1) {
      cout << 0 << endl;
      return 0;
    }
  }

  vector<ll> ans(N + 1, 0);
  ans[0] = 1;
  ll cur = 0;
  if (cur < M && a[cur] == 1) {
    ans[1] = 0;
    cur++;
  } else {
    ans[1] = 1;
  }

  for (ll i = 2; i <= N; i++) {
    if (cur < M && i == a[cur]) {
      ans[i] = 0;
      cur++;
    } else {
      ans[i] = (ans[i - 1] + ans[i - 2]);
      ans[i] %= MOD;
    }
  }

  cout << ans[N] << endl;
  return 0;
}