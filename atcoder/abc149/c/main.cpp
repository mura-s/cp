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

bool is_prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int X;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> X;

  for (int i = X; i <= 1000000; i++) {
    if (is_prime(i)) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}