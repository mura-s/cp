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

// 二次元累積和
struct CumSum2D {
  vector<vector<int>> data;

  CumSum2D(int H, int W) : data(H + 1, vector<int>(W + 1, 0)) {}

  void add(int y, int x, int z) {
    ++y, ++x;
    if (y >= data.size() || x >= data[0].size())
      return;
    data[y][x] += z;
  }

  void build() {
    for (int i = 1; i < data.size(); i++) {
      for (int j = 1; j < data[i].size(); j++) {
        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  // 左上(sy,sx), 右下(gy,gx) の矩形内の和を求める
  // (半開区間で与えることに注意すること。具体的には行gy,列gxは含まない)
  int query(int sy, int sx, int gy, int gx) {
    return (data[gy][gx] - data[sy][gx] - data[gy][sx] + data[sy][sx]);
  }
};

int M, N, K;

// https://atcoder.jp/contests/joi2011ho/tasks/joi2011ho1
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> M >> N >> K;
  CumSum2D cs_j(M, N);
  CumSum2D cs_o(M, N);
  CumSum2D cs_i(M, N);
  rep(i, M) {
    string s;
    cin >> s;
    rep(j, s.size()) {
      if (s[j] == 'J') {
        cs_j.add(i, j, 1);
      } else if (s[j] == 'O') {
        cs_o.add(i, j, 1);
      } else {
        cs_i.add(i, j, 1);
      }
    }
  }
  cs_j.build();
  cs_o.build();
  cs_i.build();

  rep(i, K) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    cout << cs_j.query(a, b, c + 1, d + 1) << " ";
    cout << cs_o.query(a, b, c + 1, d + 1) << " ";
    cout << cs_i.query(a, b, c + 1, d + 1) << endl;
  }
  return 0;
}
