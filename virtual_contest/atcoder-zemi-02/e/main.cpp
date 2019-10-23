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
vector<ll> A, B, C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  B.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  sort(B.begin(), B.end());
  C.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  sort(C.begin(), C.end());

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll b = B[i];
    ll a_pos = lower_bound(A.begin(), A.end(), b) - A.begin();
    ll c_pos = upper_bound(C.begin(), C.end(), b) - C.begin();
    if (a_pos == 0 || c_pos == N) {
      continue;
    }
    ans += (a_pos * (N - c_pos));
  }

  cout << ans << endl;
  return 0;
}