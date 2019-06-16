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

ll W, H, x, y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> W >> H >> x >> y;

  double ans = 0.0;
  bool multi = false;
  if (W * y == H * x) {
    multi = true;
  }
  if (x == 0 && y == 0) {
    multi = false;
  }
  if (W == x && H == y) {
    multi = false;
  }
  ans = (double)W * (double)H / (double)2;

  cout << fixed << setprecision(10) << ans << " ";
  if (multi) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}