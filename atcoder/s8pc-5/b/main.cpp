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

const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

int N, M;
vector<int> x, y, r;
vector<int> xm, ym;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  x.resize(N);
  y.resize(N);
  r.resize(N);
  rep(i, N) { cin >> x[i] >> y[i] >> r[i]; }
  xm.resize(M);
  ym.resize(M);
  rep(i, M) { cin >> xm[i] >> ym[i]; }

  double ans = (double)INF;
  rep(i, N) { ans = min(ans, (double)r[i]); }
  if (M != 0) {
    rep(i, M) {
      rep(j, N) {
        double d = sqrt(pow(xm[i] - x[j], 2) + pow(ym[i] - y[j], 2));
        ans = min(ans, d - r[j]);
      }
      rep(j, M) {
        if (i != j) {
          double d = sqrt(pow(xm[i] - xm[j], 2) + pow(ym[i] - ym[j], 2));
          ans = min(ans, d / 2);
        }
      }
    }
  }
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}
