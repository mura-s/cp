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
using namespace std;
typedef long long ll;
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int N, M;
vector<int> s, c;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  s.resize(M);
  c.resize(M);
  for (int i = 0; i < M; i++) {
    int si, ci;
    cin >> si >> ci;
    si--;
    s[i] = si;
    c[i] = ci;
  }

  vector<int> ans(N, -1);
  for (int i = 0; i < M; i++) {
    if (ans[s[i]] == -1) {
      ans[s[i]] = c[i];
    } else {
      if (ans[s[i]] != c[i]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  if (N == 1 && ans[0] == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (N == 1 && ans[0] == -1) {
    cout << 0 << endl;
    return 0;
  }

  if (ans[0] == 0) {
    cout << -1 << endl;
    return 0;
  }
  if (ans[0] == -1) {
    ans[0] = 1;
  }

  for (auto &e : ans) {
    if (e == -1) {
      cout << 0;
    } else {
      cout << e;
    }
  }
  cout << endl;
  return 0;
}
