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

ll N;
vector<pair<ll, ll>> xy;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  xy.resize(N);
  for (int i = 0; i < N; i++) {
    ll xi, yi;
    cin >> xi >> yi;
    xy[i] = make_pair(xi, yi);
  }
  sort(xy.begin(), xy.end());

  map<pair<ll, ll>, ll> mp;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      ll dx = xy[j].first - xy[i].first;
      ll dy = xy[j].second - xy[i].second;
      mp[make_pair(dx, dy)]++;
    }
  }

  ll m = 0;
  for (auto &e : mp) {
    m = max(m, e.second);
  }
  cout << N - m << endl;
  return 0;
}