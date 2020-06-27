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
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

ll N;
vector<ll> d;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  d.resize(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    int j = i;
    do {
      d[j]++;
      j += i;
    } while (j <= N);
  }

  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += (i * d[i]);
  }
  cout << ans << endl;
  return 0;
}
