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

int N, D;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> D;

  int range = 2 * D + 1;
  int ans = N / range;

  if (N % range == 0) {
    cout << ans << endl;
  } else {
    cout << ans + 1 << endl;
  }

  return 0;
}