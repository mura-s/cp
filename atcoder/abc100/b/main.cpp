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

int D, N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> D >> N;

  int ans = 0;
  int cnt = 0;
  for (int i = 1; i < 10000000; i++) {
    if (D == 0) {
      if (i % 100 != 0) {
        cnt++;
      }
    } else if (D == 1) {
      if (i % 100 == 0 && i % 10000 != 0) {
        cnt++;
      }
    } else {
      if (i % 10000 == 0 && i % 1000000 != 0) {
        cnt++;
      }
    }

    if (cnt == N) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}