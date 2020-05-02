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

int N;
vector<int> P;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  P.resize(N);
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    P[i] = tmp;
  }

  int ans = 0;
  int m = INF;
  for (int i = 0; i < N; i++) {
    if (P[i] <= m) {
      ans++;
    }
    m = min(m, P[i]);
  }

  cout << ans << endl;
  return 0;
}
