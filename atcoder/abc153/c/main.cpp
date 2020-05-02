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
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

ll N, K;
vector<ll> H;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  H.resize(N);
  for (int i = 0; i < N; i++) {
    ll tmp;
    cin >> tmp;
    H[i] = tmp;
  }

  sort(H.begin(), H.end(), greater<int>());
  ll ans = 0;
  for (int i = 0; i < H.size(); i++) {
    if (K > 0) {
      K--;
      continue;
    }
    ans += H[i];
  }

  cout << ans << endl;
  return 0;
}
