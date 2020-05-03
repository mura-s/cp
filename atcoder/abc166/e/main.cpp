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

ll N;
map<ll, ll> mpl;
map<ll, ll> mpr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (ll i = 0; i < N; i++) {
    ll tmp;
    cin >> tmp;
    mpl[i + tmp]++;
    mpr[i - tmp]++;
  }

  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ans += (mpl[i] * mpr[i]);
  }

  cout << ans << endl;
  return 0;
}
