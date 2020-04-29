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

ll N, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;

  ll ans = 0;
  for (ll i = K; i <= N + 1; i++) {
    ll u = i * (N - i + 1 + N) / 2;
    ll l = i * (i - 1) / 2;
    ans += u - l + 1;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}