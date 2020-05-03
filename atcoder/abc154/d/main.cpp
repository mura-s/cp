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

int N, K;
vector<int> pi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  pi.resize(N);
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    pi[i] = tmp;
  }

  vector<double> cum(N + 1, 0);
  for (int i = 0; i < N; i++) {
    cum[i + 1] = cum[i];
    cum[i + 1] += (double)(pi[i] * (pi[i] + 1) / 2) / (double)(pi[i]);
  }
  double ans = 0;
  for (int i = K; i <= N; i++) {
    ans = max(ans, cum[i] - cum[i - K]);
  }

  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}
