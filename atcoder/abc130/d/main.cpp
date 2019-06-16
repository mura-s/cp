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

ll N, K;
vector<ll> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  a.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  ll ans = 0;
  ll l = 0;
  ll r = 0;
  ll sum = a[r];
  while (r < N) {
    while (l <= r && sum >= K) {
      if (sum >= K) {
        ans += (N - r);
      }
      sum -= a[l];
      l++;
    }
    r++;
    sum += a[r];
  }

  cout << ans << endl;
  return 0;
}