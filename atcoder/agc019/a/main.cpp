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
// const ll MOD = 1e9 + 7;

ll Q, H, S, D;
ll N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> Q >> H >> S >> D;
  cin >> N;
  N *= 4;

  vector<pair<ll, ll>> sizes = {
      make_pair(1, Q),
      make_pair(2, H),
      make_pair(4, S),
      make_pair(8, D),
  };

  ll ans = LL_INF;
  do {
    ll n = N;
    ll a = 0;
    for (int i = 0; i < 4; i++) {
      if (sizes[i].first <= n) {
        ll num = n / sizes[i].first;
        a += (sizes[i].second * num);
        n -= (sizes[i].first * num);
      }
    }
    if (n == 0) {
      ans = min(ans, a);
    }
  } while (next_permutation(sizes.begin(), sizes.end()));

  cout << ans << endl;
  return 0;
}