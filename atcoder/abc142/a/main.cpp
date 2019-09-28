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

  double ans = 0.0;
  if (N % 2 == 0) {
    int tmp = N / 2;
    ans = (double)tmp / N;
  } else {
    int tmp = N / 2;
    ans = ((double)tmp + 1.0) / N;
  }

  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}