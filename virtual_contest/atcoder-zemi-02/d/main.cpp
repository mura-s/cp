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

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  map<ll, ll> mp;
  for (int i = 0; i < N; i++) {
    ll tmp;
    cin >> tmp;
    mp[tmp]++;
  }

  ll ans = 0;
  for (auto &e : mp) {
    if (e.first < e.second) {
      ans += (e.second - e.first);
    } else if (e.first > e.second) {
      ans += e.second;
    }
  }

  cout << ans << endl;
  return 0;
}