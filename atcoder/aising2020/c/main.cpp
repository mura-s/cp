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
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

int N;
int ans[10001];

int f(int x, int y, int z) { return x * x + y * y + z * z + x * y + y * z + z * x; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;

  for (int x = 1; x <= 100; x++) {
    for (int y = 1; y <= 100; y++) {
      for (int z = 1; z <= 100; z++) {
        int sum = f(x, y, z);
        if (sum <= N) {
          ans[sum]++;
        }
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
