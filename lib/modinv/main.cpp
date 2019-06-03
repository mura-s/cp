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

// 拡張 Euclid の互除法を用いて、mod MOD での a の逆元 a^{-1} を計算する
// 計算量: O(logMOD)
//
// ref. https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#3-%E5%89%B2%E3%82%8A%E7%AE%97-a--b
ll modinv(ll a) {
  ll b = MOD, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= MOD;
  if (u < 0) {
    u += MOD;
  }
  return u;
}

int main() {
  ll x = 678813585;
  ll y = 100000;

  // (x / y) % MOD を計算
  cout << x * modinv(y) % MOD << endl;
}
