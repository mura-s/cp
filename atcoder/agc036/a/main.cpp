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

ll S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;

  ll x1 = 0, y1 = 0;
  ll x2 = 1e9, y2 = 1;

  // S = x2 * y3 - x3
  ll y3 = ceil((double)S / (double)x2);
  ll x3 = x2 * y3 - S;

  cout << x1 << " " << y1 << " ";
  cout << x2 << " " << y2 << " ";
  cout << x3 << " " << y3 << endl;
  return 0;
}