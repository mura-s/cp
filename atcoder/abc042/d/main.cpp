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
// const ll MOD = 1e9 + 7;

const ll MOD = 1000000007;
const int MAX = 200001;
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

// 二項係数計算 (combination. nCkを求める.)
ll comb(int n, int k) {
  if (n < k) {
    return 0;
  }
  if (n < 0 || k < 0) {
    return 0;
  }
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll H, W, A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  comb_init();

  cin >> H >> W >> A >> B;

  ll ans = 0;
  for (ll h = 0; h < H - A; h++) {
    ll w1 = B - 1;
    ll w2 = B;
    ll w_end = W - 1;
    ll h_end = H - 1;
    ans += comb(w1 + h, w1) * comb(h_end - h + w_end - w2, w_end - w2);
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}