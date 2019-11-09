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
// 4611686018427387903
const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

ll N, M;
vector<tuple<ll, ll, ll>> lrc;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  lrc.resize(M);
  for (int i = 0; i < M; i++) {
    ll l, r, c;
    cin >> l >> r >> c;
    l--;
    r--;
    lrc[i] = make_tuple(l, r, c);
  }
  sort(lrc.begin(), lrc.end());

  vector<ll> ans(N, LL_INF);
  ans[0] = 0;
  for (int i = 0; i < M; i++) {
    ll l = get<0>(lrc[i]);
    ll r = get<1>(lrc[i]);
    if (ans[l] == LL_INF) {
      continue;
    }
    ll v = ans[l] + get<2>(lrc[i]);
    ll pos = upper_bound(ans.begin() + l, ans.begin() + r + 1, v) - ans.begin();
    while (pos <= r) {
      ans[pos] = v;
      pos++;
    }
  }

  if (ans[N - 1] == LL_INF) {
    cout << -1 << endl;
  } else {
    cout << ans[N - 1] << endl;
  }
  return 0;
}