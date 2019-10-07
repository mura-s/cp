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
  int n = N;
  int fx = 0;
  while (n > 0) {
    fx += (n % 10);
    n /= 10;
  }

  if (N % fx == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}