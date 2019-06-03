#include <algorithm>
#include <cassert>
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

string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;

  ll ans = 0;
  ll a_num = 0;
  ll b_num = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A' && b_num == 0) {
      a_num++;
    } else if (s[i] == 'B' && a_num > 0 && b_num == 0) {
      b_num++;
    } else if (s[i] == 'C' && a_num > 0 && b_num > 0) {
      ans += a_num;
      b_num = 0;
    } else {
      a_num = 0;
      b_num = 0;
      if (s[i] == 'A') {
        a_num++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}