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

string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;

  int ans = 0;
  string s_prev = "";
  for (int i = 0; i < S.size(); i++) {
    string s{S[i]};
    if (s != s_prev) {
      ans++;
    } else {
      if (i + 1 < S.size()) {
        s += S[i + 1];
        ans++;
        i++;
      }
    }
    s_prev = s;
  }

  cout << ans << endl;
  return 0;
}