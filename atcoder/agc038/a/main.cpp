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

int H, W, A, B;
int s[1001][1001];

void output() {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << s[i][j];
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W >> A >> B;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (j < A && i < B) {
        s[i][j] = 0;
      } else if (j >= A && i < B) {
        s[i][j] = 1;
      } else if (j < A && i >= B) {
        s[i][j] = 1;
      } else {
        s[i][j] = 0;
      }
    }
  }

  output();
  return 0;
}
