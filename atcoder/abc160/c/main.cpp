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
const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int K, N;
vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> K >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    A[i] = tmp;
  }

  int ans = INF;
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      ans = min(ans, K - abs(K - A[i]) - abs(A[0]));
    } else {
      ans = min(ans, K - abs(A[i + 1] - A[i]));
    }
  }

  cout << ans << endl;
  return 0;
}
