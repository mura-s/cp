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
const ll MOD = 998244353;

ll power(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

ll N;
vector<ll> D;
ll d1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  D.resize(N, 0);
  for (ll i = 0; i < N; i++) {
    ll d;
    cin >> d;
    D[d]++;
    if (i == 0) {
      d1 = d;
    }
  }

  bool flag = false;
  bool flag2 = false;
  if (d1 != 0) {
    flag = true;
  }
  if (D[0] > 1) {
    flag = true;
  }
  for (ll i = 0; i < N; i++) {
    if (flag2 && D[i] > 0) {
      flag = true;
    }
    if (D[i] == 0) {
      flag2 = true;
    }
  }
  if (flag) {
    cout << 0 << endl;
    return 0;
  }

  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }

  ll ans = 1;
  for (ll i = 2; i < N; i++) {
    if (D[i] == 0) {
      break;
    }
    ans *= power(D[i - 1], D[i]);
    ans %= MOD;
  }

  cout << ans % MOD << endl;
  return 0;
}