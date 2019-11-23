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

int X, Y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> X >> Y;

  int ans = 0;
  if (X == 1) {
    ans += 300000;
  } else if (X == 2) {
    ans += 200000;
  } else if (X == 3) {
    ans += 100000;
  }
  if (Y == 1) {
    ans += 300000;
  } else if (Y == 2) {
    ans += 200000;
  } else if (Y == 3) {
    ans += 100000;
  }

  if (X == 1 && Y == 1) {
    ans += 400000;
  }

  cout << ans << endl;
  return 0;
}