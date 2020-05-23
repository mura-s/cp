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
// const double PI = M_PI;

ll N, A, B;
// vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> A >> B;
  // A.resize(N);
  // for (int i = 0; i < N; i++) {
  //   int tmp;
  //   cin >> tmp;
  //   A[i] = tmp;
  // }

  ll ans = 0;
  if ((B - A) % 2 == 0) {
    ans = (B - A) / 2;
  } else {
    ans = min(B - 1, N - A);
    ans = min(ans, A + (B - A - 1) / 2);
    ans = min(ans, N - B + 1 + (N - (A + N - B + 1)) / 2);
  }
  cout << ans << endl;
  return 0;
}
