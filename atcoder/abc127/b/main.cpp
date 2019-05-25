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

int r, D, x;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> r >> D >> x;

  for (int i = 1; i <= 10; i++) {
    int ans = r * x - D;
    cout << ans << endl;
    x = ans;
  }
  return 0;
}