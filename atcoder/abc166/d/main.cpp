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
// const ll MOD = 1e9 + 7;

ll power(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x;
    }
    x = x * x;
    n >>= 1;
  }
  return res;
}

ll X;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> X;

  for (ll a = -200; a <= 200; a++) {
    for (ll b = -200; b <= 200; b++) {
      if (power(a, 5) - power(b, 5) == X) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }

  return 0;
}
