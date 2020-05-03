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

string S;
int Q;
// vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S >> Q;

  string ans = S;
  bool rev = false;
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      rev = !rev;
    } else {
      int f;
      string c;
      cin >> f >> c;
      if ((f == 1 && rev) || (f == 2 && !rev)) {
        ans.append(c);
      } else {
        ans.insert(0, c);
      }
    }
  }

  if (rev) {
    reverse(ans.begin(), ans.end());
  }

  cout << ans << endl;
  return 0;
}
