#include <algorithm>
#include <climits>
#include <cmath>
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
// const ll MOD = 1000000007;
// const int INF = 2000000000;

int X, t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> X >> t;

  cout << max(X - t, 0) << endl;
  return 0;
}