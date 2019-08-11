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

// 組み合わせ (combination) を求める
ll nCr(ll n, ll r) {
  if (r > n) {
    return 0;
  }
  if (r == 0 || n == r) {
    return 1;
  }
  if (r * 2 > n) {
    r = n - r;
  }

  ll result = n;
  for (ll i = 2; i <= r; i++) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}

ll N;
map<string, ll> mp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    mp[s]++;
  }

  ll ans = 0;
  for (auto &e : mp) {
    ans += nCr(e.second, 2);
  }

  cout << ans << endl;
  return 0;
}