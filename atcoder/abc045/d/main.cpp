#include <algorithm>
#include <climits>
#include <cmath>
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

ll H, W, N;
vector<ll> a, b;
map<ll, set<ll>> mp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W >> N;
  a.resize(N);
  b.resize(N);
  for (ll i = 0; i < N; i++) {
    ll ai, bi;
    cin >> ai >> bi;
    ai--;
    bi--;
    a[i] = ai;
    b[i] = bi;
    mp[ai].insert(bi);
  }

  set<pair<ll, ll>> used;
  vector<ll> ans(10, 0);
  for (ll i = 0; i < N; i++) {
    ll ai = a[i], bi = b[i];
    for (ll h = ai - 2; h <= ai; h++) {
      for (ll w = bi - 2; w <= bi; w++) {
        pair<ll, ll> p = make_pair(h, w);
        if (0 <= h && h < H - 2 && 0 <= w && w < W - 2 && used.find(p) == used.end()) {
          used.insert(p);
          ll cnt = 0;
          for (ll j = h; j < h + 3; j++) {
            for (ll k = w; k < w + 3; k++) {
              if (!mp[j].empty() && mp[j].find(k) != mp[j].end()) {
                cnt++;
              }
            }
          }
          ans[cnt]++;
        }
      }
    }
  }

  ll sum = 0;
  for (auto &e : ans) {
    sum += e;
  }
  ans[0] = (H - 2) * (W - 2) - sum;
  for (auto &e : ans) {
    cout << e << endl;
  }
  return 0;
}