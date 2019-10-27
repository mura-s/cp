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
#define PI 3.141592653589793
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

double a, b, x;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> x;

  double ans = 0.0;
  if (a * a * b <= 2 * x) {
    double h = (b - (x / (a * a))) * 2;
    ans = atan2(h, a) * 180.0 / PI;
  } else {
    double w = x / (a * b) * 2;
    ans = atan2(b, w) * 180.0 / PI;
  }

  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}