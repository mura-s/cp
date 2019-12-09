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
vector<vector<pair<int, int>>> vvp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  vvp.resize(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    vvp[i].resize(a);
    for (int j = 0; j < a; j++) {
      int x, y;
      cin >> x >> y;
      x--;
      vvp[i][j] = make_pair(x, y);
    }
  }

  int ans = 0;
  int m = 1 << N;
  for (int i = 0; i < m; i++) {
    vector<int> trust(N, 0);
    int b = i;
    int j = 0;
    int cnt = 0;
    while (b > 0) {
      if (b % 2 != 0) {
        trust[j] = 1;
        cnt++;
      }
      b /= 2;
      j++;
    }

    bool flag = true;
    for (int j = 0; j < N; j++) {
      if (trust[j] == 1) {
        for (int k = 0; k < vvp[j].size(); k++) {
          int x = vvp[j][k].first;
          int y = vvp[j][k].second;
          if (y != trust[x]) {
            flag = false;
            break;
          }
        }
      }
    }

    if (flag) {
      ans = max(ans, cnt);
    }
  }

  cout << ans << endl;
  return 0;
}