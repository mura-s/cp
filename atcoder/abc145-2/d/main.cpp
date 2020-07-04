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
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

const ll MOD = 1000000007;
const int MAX = 2000001;

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

// 二項係数計算 (combination)
// nCk = (n!) * (k!)^-1 * ((n-k)!)^-1 として計算
ll comb(int n, int k) {
  if (n < k) {
    return 0;
  }
  if (n < 0 || k < 0) {
    return 0;
  }
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll X, Y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> X >> Y;
  if ((X + Y) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  comb_init();

  ll ans = 0;
  ll num = (X + Y) / 3;
  for (int i = 0; i <= num; i++) {
    int j = num - i;
    if (i + 2 * j == X && 2 * i + j == Y) {
      ans += comb(i + j, i);
      ans %= MOD;
    }
  }

  cout << ans << endl;
  return 0;
}
