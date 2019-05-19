#include <algorithm>
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
// const ll MOD = 1000000007;
const ll INF = LONG_MAX;

struct xy {
  ll x, y;
};

int N, K;
vector<ll> x, y;
vector<xy> xy_comb;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  x.resize(N);
  y.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  xy_comb.resize(N * N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      xy_comb[i * N + j] = xy{x[i], y[j]};
    }
  }

  ll ans = INF;
  for (int i = 0; i < N * N; i++) {
    for (int j = i + 1; j < N * N; j++) {
      ll x_min = min(xy_comb[i].x, xy_comb[j].x);
      ll x_max = max(xy_comb[i].x, xy_comb[j].x);
      ll y_min = min(xy_comb[i].y, xy_comb[j].y);
      ll y_max = max(xy_comb[i].y, xy_comb[j].y);

      int k = 0;
      for (int i = 0; i < N; i++) {
        if (x_min <= x[i] && x[i] <= x_max && y_min <= y[i] && y[i] <= y_max) {
          k++;
        }
      }

      if (k >= K) {
        ans = min(ans, (x_max - x_min) * (y_max - y_min));
      }
    }
  }

  cout << ans << endl;
  return 0;
}