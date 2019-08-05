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

int N;
vector<int> H;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  H.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  bool ans = true;
  int m = H[0];
  for (int i = 1; i < N; i++) {
    if (H[i] < m - 1) {
      ans = false;
      break;
    } else if (H[i] == m - 1) {
      // do nothing
    } else {
      m = H[i];
    }
  }

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}