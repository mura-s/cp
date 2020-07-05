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

int H, W, K;
char c[7][7];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W >> K;
  rep(i, H) {
    rep(j, W) { cin >> c[i][j]; }
  }

  int ans = 0;
  for (int i = 0; i < (1 << H); i++) {
    for (int j = 0; j < (1 << W); j++) {
      int cnt = 0;
      for (int k = 0; k < H; k++) {
        for (int l = 0; l < W; l++) {
          if ((i & (1 << k)) == 0 && (j & (1 << l)) == 0 && c[k][l] == '#') {
            cnt++;
          }
        }
      }
      if (cnt == K) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
