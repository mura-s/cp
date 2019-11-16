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

int N;
vector<pair<double, double>> xy;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  xy.resize(N);
  for (int i = 0; i < N; i++) {
    double x, y;
    cin >> x >> y;
    xy[i] = make_pair(x, y);
  }
  sort(xy.begin(), xy.end());

  int num = 1;
  for (int i = 1; i <= N; i++) {
    num *= i;
  }

  double ans = 0.0;
  do {
    for (int i = 1; i < N; i++) {
      double x = xy[i - 1].first - xy[i].first;
      double y = xy[i - 1].second - xy[i].second;
      ans += sqrt(x * x + y * y);
    }
  } while (next_permutation(xy.begin(), xy.end()));
  ans /= num;

  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}