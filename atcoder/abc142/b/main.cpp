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

int N, K;
vector<int> h;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  h.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (h[i] >= K) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}