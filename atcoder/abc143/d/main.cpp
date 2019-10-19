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
vector<int> L;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  L.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }
  sort(L.begin(), L.end());

  int ans = 0;
  for (int i = 2; i < N; i++) {
    for (int j = i - 1; j >= 0; j--) {
      int k = upper_bound(L.begin(), L.begin() + j, L[i] - L[j]) - L.begin();
      if (k != j) {
        ans += (j - k);
      }
    }
  }

  cout << ans << endl;
  return 0;
}