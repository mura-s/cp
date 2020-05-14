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

int A, B, C, K;
// vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> C >> K;
  // A.resize(N);
  // for (int i = 0; i < N; i++) {
  //   int tmp;
  //   cin >> tmp;
  //   A[i] = tmp;
  // }

  int ans = 0;
  if (K > 0) {
    int cnt = min(K, A);
    ans += cnt;
    K -= cnt;
  }

  if (K > 0) {
    int cnt = min(K, B);
    K -= cnt;
  }

  if (K > 0) {
    int cnt = min(K, C);
    ans -= cnt;
    K -= cnt;
  }

  cout << ans << endl;
  return 0;
}
