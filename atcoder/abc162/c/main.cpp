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
using namespace std;
typedef long long ll;
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

ll K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> K;

  ll ans = 0;
  for (ll a = 1; a <= K; a++) {
    for (ll b = 1; b <= K; b++) {
      for (ll c = 1; c <= K; c++) {
        ans += gcd(gcd(a, b), c);
      }
    }
  }

  cout << ans << endl;
  return 0;
}