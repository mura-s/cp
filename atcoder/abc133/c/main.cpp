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
const ll LL_INF = (1LL << 62) - 1;
const ll MOD = 2019;

ll L, R;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> L >> R;

  ll ans = LL_INF;
  for (ll k = L; k <= min(R, L + 2019); k++) {
    for (ll l = k + 1; l <= min(R, L + 2019); l++) {
      ll sum = k * l % MOD;
      if (sum == 0) {
        cout << 0 << endl;
        return 0;
      }

      if (sum < ans) {
        ans = sum;
      }
    }
  }

  cout << ans << endl;
  return 0;
}