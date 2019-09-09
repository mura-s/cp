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

int tx_a, ty_a, tx_b, ty_b;
int T, V;
int n;
vector<int> x, y;

double dist(int x1, int y1, int x2, int y2) { return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> tx_a >> ty_a >> tx_b >> ty_b >> T >> V;
  cin >> n;
  x.resize(n);
  y.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  double max_dist = T * V;
  for (int i = 0; i < n; i++) {
    bool flag = false;
    double dist_i = dist(tx_a, ty_a, x[i], y[i]) + dist(x[i], y[i], tx_b, ty_b);
    if (dist_i <= max_dist) {
      flag = true;
    }

    if (flag) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}