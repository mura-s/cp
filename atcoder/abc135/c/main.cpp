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
vector<ll> A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N + 1);
  for (int i = 0; i < N + 1; i++) {
    cin >> A[i];
  }
  B.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  ll ans = 0;
  ll r = 0;
  for (int i = 0; i < N; i++) {
    ll a = A[i];
    ll b = B[i];
    ans += min(r, a);
    a -= r;
    if (a > 0) {
      ans += min(b, a);
      b -= a;
      if (b > 0) {
        r = b;
      } else {
        r = 0;
      }
    } else {
      r = b;
    }
  }
  ans += min(r, A[N]);

  cout << ans << endl;
  return 0;
}