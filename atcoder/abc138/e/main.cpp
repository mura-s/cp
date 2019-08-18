#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

string s, t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s >> t;

  unordered_map<char, vector<int>> mp;
  for (int i = 0; i < s.size(); i++) {
    mp[s[i]].push_back(i);
  }
  bool ok = true;
  for (int i = 0; i < t.size(); i++) {
    if (mp.find(t[i]) == mp.end()) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }

  long l = 1;
  long ans = 0;
  long cur = -1;
  for (int i = 0; i < t.size(); i++) {
    vector<int> &v = mp[t[i]];
    auto ub = upper_bound(v.begin(), v.end(), cur);
    long idx = 0;
    if (ub == v.end()) {
      ans = l * s.size();
      l++;
      cur = -1;
      idx = v[0];
      ans = ans + idx + 1;
    } else {
      idx = *ub;
      ans = ans - (cur + 1) + idx + 1;
    }
    cur = idx;
  }

  cout << ans << endl;
  return 0;
}
