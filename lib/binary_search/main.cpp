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

const ll X = 3;
const ll VEC_LEN = 5;
vector<ll> vec = {1, 3, 3, 4, 5};

bool check(ll v) {
  // TODO: implement check
  return vec[v] > X;
}

ll binary_search(ll k) {
  ll left = 0;
  ll right = k; // always satisfied with the check.
  while (left < right) {
    ll mid = (left + right) / 2;
    if (check(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return right;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cout << binary_search(VEC_LEN) << endl;
  return 0;
}