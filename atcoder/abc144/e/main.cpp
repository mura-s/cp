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
vector<ll> A, F;

bool check(ll v) {
  ll num = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] * F[i] > v) {
      num += (A[i] - (v / F[i]));
    }
  }
  return num <= K;
}

ll binary_search(ll k) {
  ll left = 0;
  ll right = k;
  ll ans = k;
  while (left < right) {
    ll mid = (left + right) / 2;
    if (check(mid)) {
      ans = min(ans, mid);
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  F.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> F[i];
  }
  sort(A.begin(), A.end());
  sort(F.begin(), F.end(), greater<ll>());
  ll m = 0;
  for (int i = 0; i < N; i++) {
    m = max(m, A[i] * F[i]);
  }

  cout << binary_search(m) << endl;
  return 0;
}