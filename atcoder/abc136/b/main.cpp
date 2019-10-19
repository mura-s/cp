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

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int n = i;
    int bit = 0;
    while (n > 0) {
      n /= 10;
      bit++;
    }
    if (bit % 2 != 0) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}