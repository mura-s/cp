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

int n;
int imos[1000002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    imos[a]++;
    imos[b + 1]--;
  }

  int ans = imos[0];
  rep(i, 1000001) {
    imos[i + 1] += imos[i];
    ans = max(ans, imos[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
