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

int N, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;

  if (K == 1) {
    cout << 0 << endl;
  } else {
    int ans = N - K;
    cout << ans << endl;
  }

  return 0;
}