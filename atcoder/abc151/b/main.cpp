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

int N, K, M;
vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K >> M;
  A.resize(N - 1);
  for (int i = 0; i < N - 1; i++) {
    cin >> A[i];
  }

  int ans = M * N;
  for (int i = 0; i < N - 1; i++) {
    ans -= A[i];
  }

  if (ans > K) {
    cout << -1 << endl;
  } else if (ans <= 0) {
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}