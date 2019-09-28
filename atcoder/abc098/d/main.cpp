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

ll N;
vector<ll> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<ll> cum_sum(N + 1, 0);
  vector<ll> cum_xor(N + 1, 0);
  for (int i = 0; i < N; i++) {
    cum_sum[i + 1] = cum_sum[i] + A[i];
    cum_xor[i + 1] = cum_xor[i] ^ A[i];
  }

  ll ans = 0;
  ll r = 1;
  for (ll l = 0; l < N; l++) {
    ll sum = cum_sum[r] - cum_sum[l];
    ll xr = cum_xor[r] ^ cum_xor[l];
    while (r <= N && sum == xr) {
      ans += (r - l);
      r++;
      sum = cum_sum[r] - cum_sum[l];
      xr = cum_xor[r] ^ cum_xor[l];
    }
  }

  cout << ans << endl;
  return 0;
}