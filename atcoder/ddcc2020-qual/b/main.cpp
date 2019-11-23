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

ll N;
vector<ll> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  vector<ll> cum(N + 1, 0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    cum[i + 1] = cum[i] + A[i];
  }

  ll ans = LL_INF;
  for (int i = 1; i < N; i++) {
    ll h1 = cum[i] - cum[0];
    ll h2 = cum[N] - cum[i];
    ans = min(ans, abs(h2 - h1));
  }

  cout << ans << endl;
  return 0;
}