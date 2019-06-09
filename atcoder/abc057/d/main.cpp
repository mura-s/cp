#include <algorithm>
#include <boost/multiprecision/cpp_dec_float.hpp>
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

namespace mp = boost::multiprecision;
using Real1024 = mp::number<mp::cpp_dec_float<1024>>;

ll nCr(ll n, ll r) {
  if (r > n) {
    return 0;
  }
  if (r == 0 || n == r) {
    return 1;
  }
  if (r * 2 > n) {
    r = n - r;
  }

  ll result = n;
  for (ll i = 2; i <= r; i++) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}

ll N, A, B;
vector<ll> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> A >> B;
  v.resize(N);
  for (ll i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end(), greater<ll>());

  Real1024 ans_avg = 0;
  ll ans_cnt = 0;
  for (ll i = A; i <= B; i++) {
    map<ll, ll, greater<ll>> mp;
    ll cur = 0;
    ll last = 0;
    while (cur < i) {
      mp[v[cur]]++;
      last = v[cur];
      cur++;
    }
    while (cur < v.size() && v[cur] == last) {
      mp[v[cur]]++;
      cur++;
    }

    ll ll_avg = 0;
    cur = 0;
    for (auto &e : mp) {
      if (mp.rbegin()->first == e.first) {
        ll_avg += (e.first * (i - cur));
      } else {
        ll_avg += (e.first * e.second);
        cur += e.second;
      }
    }
    Real1024 avg = ll_avg;
    avg /= i;
    ll cnt = nCr(mp.rbegin()->second, i - cur);

    if (avg > ans_avg) {
      ans_avg = avg;
      ans_cnt = cnt;
    } else if (avg == ans_avg) {
      ans_cnt += cnt;
    }
  }

  cout << fixed << setprecision(6) << ans_avg << endl;
  cout << ans_cnt << endl;
  return 0;
}