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

int A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B;

  int ans = 0;
  if (A >= 13) {
    ans = B;
  } else if (6 <= A && A <= 12) {
    ans = B / 2;
  }

  cout << ans << endl;
  return 0;
}