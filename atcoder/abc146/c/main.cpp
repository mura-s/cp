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
// const ll MOD = 1e9 + 7;
const ll m = pow(10LL, 9LL);

ll A, B, X;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> X;

  ll ans = 0;
  for (ll i = 1; i <= 10; i++) {
    ll num = (X - B * i) / A;
    if (num < 0) {
      continue;
    }
    ll d = to_string(num).size();
    if (d == i) {
      ans = max(ans, num);
    } else if (d > i) {
      ll l = pow(10LL, i) - 1;
      ans = max(ans, l);
    }
  }
  ans = min(ans, m);

  cout << ans << endl;
  return 0;
}