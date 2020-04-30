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
// const ll LL_INF = (1LL << 62) - 1;
const ll MOD = 1e9 + 7;

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
vector<ll> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    ll ai;
    cin >> ai;
    A[i] = ai;
  }

  ll ans = 0;
  for (ll d = 0; d < 60; d++) {
    ll n0 = 0, n1 = 0;
    for (ll i = 0; i < A.size(); i++) {
      ll r = A[i] % 2;
      A[i] /= 2;
      if (r == 0) {
        n0++;
      } else {
        n1++;
      }
    }
    ans += ((power(2, d) * n0 % MOD) * n1 % MOD);
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}