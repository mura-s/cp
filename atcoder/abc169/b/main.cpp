#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = (1 << 30) - 1;
// const ll L_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

const ll MAX = pow(10, 18);
ll N;
vector<ll> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    ll tmp;
    cin >> tmp;
    A[i] = tmp;
    if (A[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1;
  for (int i = 0; i < N; i++) {
    if (ans > MAX / A[i]) {
      ans = -1;
      break;
    }
    ans *= A[i];
  }
  cout << ans << endl;
  return 0;
}
