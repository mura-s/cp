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

ll M;
vector<ll> d, c;
ll D, S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> M;
  d.resize(M);
  c.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> d[i] >> c[i];
    D += c[i];
    S += (d[i] * c[i]);
  }

  ll ans = D - 1 + (S - 1) / 9;

  cout << ans << endl;
  return 0;
}