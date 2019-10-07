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

int N, C;
vector<int> s, t, c;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> C;
  s.resize(N);
  t.resize(N);
  c.resize(N);
  map<int, vector<pair<int, int>>> mp;
  for (int i = 0; i < N; i++) {
    cin >> s[i] >> t[i] >> c[i];
    mp[c[i]].push_back(make_pair(s[i], t[i]));
  }

  vector<int> cum(200001, 0);
  for (auto &e : mp) {
    sort(e.second.begin(), e.second.end());
    int i = 0;
    while (i < e.second.size()) {
      int first = e.second[i].first;
      int cur = e.second[i].second;
      while (i + 1 < e.second.size() && cur == e.second[i + 1].first) {
        i++;
        cur = e.second[i].second;
      }
      cum[2 * first - 1]++;
      cum[2 * cur]--;
      i++;
    }
  }
  int ans = 0;
  int cur = 0;
  for (int i = 0; i < 200001; i++) {
    cur += cum[i];
    ans = max(ans, cur);
  }

  cout << ans << endl;
  return 0;
}