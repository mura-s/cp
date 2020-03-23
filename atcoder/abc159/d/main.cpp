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

ll nCr(ll n, ll r) {
  if (r > n) {
    return 0;
  }
  if (r == 0 || n == r) {
    return 1;
  }
  if (r * 2 > n) {
    r = n - r;
  }

  ll result = n;
  for (ll i = 2; i <= r; i++) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}

const int n_max = 200001;

ll N;
vector<ll> A;
vector<ll> cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  cnt.resize(n_max);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] = a;
    cnt[A[i]]++;
  }

  ll sum = 0;
  for (int i = 0; i < n_max; i++) {
    sum += nCr(cnt[i], 2);
  }

  for (int i = 0; i < N; i++) {
    ll ans = sum - nCr(cnt[A[i]], 2) + nCr(cnt[A[i]] - 1, 2);
    cout << ans << endl;
  }
  return 0;
}