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

int N;
vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  rep(i, N) { cin >> A[i]; }

  vector<int> cnts(N + 1, 0);
  int idx = 0;
  int last = 0;
  if (A[0] == 0) {
    cnts[0] = 1;
  } else {
    cnts[1] = 1;
    idx = 1;
    last = 1;
  }
  for (int i = 1; i < N; i++) {
    if (A[i] == last) {
      cnts[idx]++;
      continue;
    }
    idx++;
    if (i % 2 != 0) {
      if (idx == 1) {
        cnts[1] += cnts[0];
        cnts[0] = 0;
      } else {
        idx -= 2;
        cnts[idx] += cnts[idx + 1];
        cnts[idx + 1] = 0;
      }
      cnts[idx]++;
    } else {
      cnts[idx]++;
    }
    last = A[i];
  }

  int ans = 0;
  rep(i, N + 1) {
    if (i % 2 == 0) {
      ans += cnts[i];
    }
  }
  cout << ans << endl;
  return 0;
}
