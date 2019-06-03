#include <algorithm>
#include <climits>
#include <cmath>
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
const ll MOD = 1000003;
const int MAX = 1000003;

// fac
ll fac[MAX], finv[MAX], inv[MAX];
void fac_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// pow
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

int Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fac_init();
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    ll xi, di, ni;
    cin >> xi >> di >> ni;
    if (di == 0) {
      cout << power(xi, ni) << endl;
      continue;
    }

    ll a = xi * inv[di] % MOD;
    if (a + ni - 1 >= MOD) {
      cout << 0 << endl;
      continue;
    }

    ll ans = power(di, ni) * fac[a + ni - 1] % MOD;
    ans *= finv[a - 1];
    ans %= MOD;
    cout << ans << endl;
  }

  return 0;
}