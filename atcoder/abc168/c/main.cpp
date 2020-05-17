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
const double PI = M_PI;

double A, B, H, M;
// vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> H >> M;

  double m = M / 60.0 * 2 * PI;
  double h = H / 12.0 * 2 * PI + M / 60.0 * 2 * PI / 12;
  double rad = m - h >= 0 ? m - h : h - m;

  double ans = sqrt(A * A + B * B - 2 * A * B * cos(rad));
  cout << fixed << setprecision(20) << ans << endl;
  return 0;
}
