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

int H, W;
char G[2001][2001];
int w_sum[2001][2001];
int h_sum[2001][2001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < W; j++) {
      G[i][j] = s[j];
    }
  }

  // w_sum
  for (int i = 0; i < H; i++) {
    vector<int> v;
    int j = 0;
    int cnt = 0;
    while (j < W) {
      if (G[i][j] == '#') {
        if (cnt > 0) {
          v.push_back(cnt);
        }
        v.push_back(0);
        cnt = 0;
      } else {
        cnt++;
      }
      j++;
    }
    if (cnt > 0) {
      v.push_back(cnt);
    }

    j = 0;
    for (auto e : v) {
      if (e == 0) {
        w_sum[i][j] = 0;
        j++;
      } else {
        for (int k = 0; k < e; k++) {
          w_sum[i][j] = e;
          j++;
        }
      }
    }
  }

  // h_sum
  for (int i = 0; i < W; i++) {
    vector<int> v;
    int j = 0;
    int cnt = 0;
    while (j < H) {
      if (G[j][i] == '#') {
        if (cnt > 0) {
          v.push_back(cnt);
        }
        v.push_back(0);
        cnt = 0;
      } else {
        cnt++;
      }
      j++;
    }
    if (cnt > 0) {
      v.push_back(cnt);
    }

    j = 0;
    for (auto e : v) {
      if (e == 0) {
        h_sum[j][i] = 0;
        j++;
      } else {
        for (int k = 0; k < e; k++) {
          h_sum[j][i] = e;
          j++;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (G[i][j] == '.') {
        ans = max(ans, w_sum[i][j] + h_sum[i][j]);
      }
    }
  }

  cout << ans - 1 << endl;
  return 0;
}