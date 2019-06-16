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

int N, X;
vector<int> L;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> X;
  L.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }

  int ans = 1;
  int cur = 0;
  for (int i = 0; i < N; i++) {
    cur += L[i];
    if (cur <= X) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}