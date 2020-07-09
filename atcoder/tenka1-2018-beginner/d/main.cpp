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
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;

  ll num = 0;
  for (int i = 1; i <= 2 * N; i++) {
    if ((2 * N) % i == 0 && (2 * N) / i == (i - 1)) {
      num = i;
      break;
    }
  }

  if (num == 0) {
    cout << "No" << endl;
    return 0;
  }

  vector<vector<int>> ans(num, vector<int>(num - 1, 0));
  P posR = make_pair(0, 0);
  P posC = make_pair(1, 0);
  for (int i = 1; i <= N; i++) {
    ans[posR.first][posR.second] = i;
    ans[posC.first][posC.second] = i;
    if (posR.first == posC.first - 1 && posR.second == posC.second) {
      posR = make_pair(0, posR.second + 1);
      posC = make_pair(posC.first + 1, 0);
    } else {
      posR = make_pair(posR.first + 1, posR.second);
      posC = make_pair(posC.first, posC.second + 1);
    }
  }

  cout << "Yes" << endl;
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    cout << ans[i].size();
    rep(j, ans[i].size()) { cout << " " << ans[i][j]; }
    cout << endl;
  }

  return 0;
}
