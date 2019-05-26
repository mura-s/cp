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
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int N, M;
vector<int> k;
vector<set<int>> s;
vector<int> p;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  k.resize(M);
  s.resize(M);
  p.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++) {
      int si;
      cin >> si;
      si--;
      s[i].insert(si);
    }
  }
  for (int i = 0; i < M; i++) {
    cin >> p[i];
  }

  int ans = 0;
  for (int i = 0; i < (1 << N); i++) {
    vector<int> on(N, 0);
    int b = i;
    for (int j = 0; j < N; j++) {
      if (b % 2 == 1) {
        on[j] = 1;
      }
      b /= 2;
    }

    bool ok = true;
    for (int j = 0; j < M; j++) {
      int num = 0;
      for (int l = 0; l < N; l++) {
        if (on[l] == 0) {
          continue;
        }
        if (s[j].find(l) != s[j].end()) {
          num++;
        }
      }
      if (num % 2 != p[j]) {
        ok = false;
      }
    }

    if (ok) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}