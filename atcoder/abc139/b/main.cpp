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

int A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B;

  if (B == 1) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 1;
  int num = A;
  while (num < B) {
    ans++;
    num += (A - 1);
  }

  cout << ans << endl;
  return 0;
}