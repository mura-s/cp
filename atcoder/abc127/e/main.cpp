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

ll N, M, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  comb_init();
  cin >> N >> M >> K;

  // xを求める
  ll ans_x = 0;
  for (int d = 1; d < M; d++) {
    ll sum = d * (M - d) * N * N;
    ans_x += (sum * comb(N * M - 2, K - 2));
    ans_x = ans_x % MOD;
  }

  // yを求める
  ll ans_y = 0;
  for (int d = 1; d < N; d++) {
    ll sum = d * (N - d) * M * M;
    ans_y += (sum * comb(N * M - 2, K - 2));
    ans_y = ans_y % MOD;
  }

  ll ans = (ans_x + ans_y) % MOD;
  cout << ans << endl;
  return 0;
}