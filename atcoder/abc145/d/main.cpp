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
const int MAX = 1000000;

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
  ll n = (X + Y) / 3;
  if (abs(X - Y) > n) {
    cout << 0 << endl;
    return 0;
  }

  comb_init();
  ll ans = 0;
  ans = comb(n, (n / 2) - abs(X - Y) / 2);
  cout << ans << endl;
  return 0;
}