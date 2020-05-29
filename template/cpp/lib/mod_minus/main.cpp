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

// 負の数にも対応した MOD 演算
ll mod(ll val) {
  ll res = val % MOD;
  if (res < 0) res += MOD;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a = 2000000020;
  ll b = 20;
  ll ans = mod((a%MOD) - (b%MOD));
  cout << a%MOD << endl;
  cout << b%MOD << endl;
  cout << ans << endl;
  return 0;
}