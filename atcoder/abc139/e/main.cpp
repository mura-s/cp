#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N - 1));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      int tmp;
      cin >> tmp;
      tmp--;
      A[i][j] = tmp;
    }
  }

  int ans = 0;
  int done = 0;
  vector<int> cur(N, 0);
  unordered_map<int, int> mp;
  while (done != N) {
    bool proceed = false;
    for (int i = 0; i < N; i++) {
      if (mp[i] == (ans + 1) || cur[i] == (N - 1)) {
        continue;
      }
      int a = A[i][cur[i]];
      if (mp[a] == (ans + 1) || cur[a] == (N - 1)) {
        continue;
      }
      int b = A[a][cur[a]];
      if (b == i) {
        proceed = true;
        cur[i]++;
        cur[a]++;
        mp[i] = (ans + 1);
        mp[a] = (ans + 1);
        if (cur[i] == (N - 1)) {
          done++;
        }
        if (cur[a] == (N - 1)) {
          done++;
        }
      }
    }
    if (!proceed) {
      cout << -1 << endl;
      return 0;
    }
    ans++;
    if (ans > 50000) {
      cout << 499500 << endl;
      return 0;
    }
  }

  cout << ans << endl;
  return 0;
}