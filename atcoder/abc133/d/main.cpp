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

ll N;
vector<ll> A;
ll sum;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
  }

  vector<ll> ans(N, 0);
  // 山1について
  for (int i = 0; i < N; i++) {
    if (i % 2 != 0) {
      sum -= (2 * A[i]);
    }
  }
  ans[0] = sum;

  // 残りの山について
  for (int i = 1; i < N; i++) {
    ans[i] = 2 * A[i - 1] - ans[i - 1];
  }

  for (int i = 0; i < N; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
  return 0;
}