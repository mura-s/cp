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

const int MAX = 200001;

// fac[n]: n!
// finv[n]: (n!)^-1
// inv[n]: nの逆元
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void comb_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

ll mod(ll val) {
  ll res = val % MOD;
  if (res < 0)
    res += MOD;
  return res;
}

ll nCr(ll n, ll r) {
  ll ret = 1;
  for (ll i = 1; i <= r; i++) {
    ret = mod(ret * (n - i + 1));
    ret = mod(ret * inv[i]);
  }
  return ret;
}

ll n, a, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a >> b;
  comb_init();

  ll ans = mod(power(2, n) - 1);
  ans = mod(ans - nCr(n, a));
  ans = mod(ans - nCr(n, b));

  cout << ans << endl;
  return 0;
}
