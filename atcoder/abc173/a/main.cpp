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
// vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  // A.resize(N);
  // rep(i, N) { cin >> A[i]; }

  if (N % 1000 == 0) {
    cout << 0 << endl;
  } else {
    int ans = 1000 - (N % 1000);
    cout << ans << endl;
  }
  return 0;
}
