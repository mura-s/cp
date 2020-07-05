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
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
const ll MOD = 100000;
// const double PI = M_PI;

int n, m;
vector<ll> s, a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  s.resize(n - 1);
  rep(i, n - 1) { cin >> s[i]; }
  a.resize(m);
  rep(i, m) { cin >> a[i]; }

  vector<ll> sum(n, 0);
  rep(i, n - 1) { sum[i + 1] = sum[i] + s[i]; }

  int pos = 0;
  ll ans = 0;
  rep(i, m) {
    int next_pos = pos + a[i];
    if (pos < next_pos) {
      ans += sum[next_pos] - sum[pos];
    } else {
      ans += sum[pos] - sum[next_pos];
    }
    pos = next_pos;
  }
  cout << ans % MOD << endl;
  return 0;
}
