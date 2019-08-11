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

ll N, M;
map<ll, vector<ll>> mp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (ll i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    mp[a].push_back(b);
  }

  ll ans = 0;
  priority_queue<ll> pq;
  for (ll i = 1; i <= M; i++) {
    if (!mp[i].empty()) {
      for (auto e : mp[i]) {
        pq.push(e);
      }
    }

    if (!pq.empty()) {
      ll v = pq.top();
      pq.pop();
      ans += v;
    }
  }

  cout << ans << endl;
  return 0;
}