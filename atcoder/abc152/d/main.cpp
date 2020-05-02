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
// const ll INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int N;
// vector<ll> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;

  int ans = 0;
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      int cij = 0;
      int cji = 0;

      for (int k = 1; k <= N; k++) {
        int n = k;
        int tail = k % 10;
        int head = 0;
        while (n >= 10) {
          n /= 10;
        }
        head = n;

        if (i == head && j == tail) {
          cij++;
        }
        if (j == head && i == tail) {
          cji++;
        }
      }

      ans += cij * cji;
    }
  }

  cout << ans << endl;
  return 0;
}
