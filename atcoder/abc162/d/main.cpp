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

ll N;
string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> S;
  vector<ll> r, g;
  set<ll> b;
  for (int i = 0; i < S.size(); i++) {
    switch (S[i]) {
    case 'R':
      r.push_back(i);
      break;
    case 'G':
      g.push_back(i);
      break;
    default:
      b.insert(i);
      break;
    }
  }

  ll ans = 0;
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < g.size(); j++) {
      ans += b.size();
      if (r[i] < g[j]) {
        ll d = g[j] - r[i];
        if (b.find(r[i] - d) != b.end()) {
          ans--;
        }
        if (b.find(g[j] + d) != b.end()) {
          ans--;
        }
        if (d % 2 == 0 && b.find(r[i] + d / 2) != b.end()) {
          ans--;
        }
      } else {
        ll d = r[i] - g[j];
        if (b.find(g[j] - d) != b.end()) {
          ans--;
        }
        if (b.find(r[i] + d) != b.end()) {
          ans--;
        }
        if (d % 2 == 0 && b.find(g[j] + d / 2) != b.end()) {
          ans--;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}