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

int H, W, K;
char s[300][300];
int ans[300][300];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W >> K;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> s[i][j];
    }
  }

  // 横に切る
  int num = 1;
  bool first = true;
  for (int i = 0; i < H; i++) {
    int j = 0;
    bool found = false;
    while (j < W) {
      if (!found && s[i][j] == '#') {
        if (first) {
          first = false;
        } else {
          j = 0;
          num++;
        }
        found = true;
      }
      ans[i][j] = num;
      j++;
    }
  }

  // 縦に切る
  int h = 0;
  num = 1;
  while (h < H) {
    int h1 = h;
    int n = ans[h][0];
    while (h + 1 < H && n == ans[h + 1][0]) {
      h++;
      n = ans[h][0];
    }
    bool first = true;
    int j = 0;
    while (j < W) {
      bool found = false;
      for (int i = h1; i <= h; i++) {
        if (!found && s[i][j] == '#') {
          if (first) {
            first = false;
          } else {
            i = h1;
            num++;
          }
          found = true;
        }
        ans[i][j] = num;
      }
      j++;
    }
    h++;
    num++;
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (j != 0) {
        cout << " ";
      }
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}