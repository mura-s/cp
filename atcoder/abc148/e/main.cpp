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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;

  if (N % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0;
  ll x = 5;
  while (x <= N) {
    ans += (N / x / 2);
    x *= 5;
  }

  cout << ans << endl;
  return 0;
}