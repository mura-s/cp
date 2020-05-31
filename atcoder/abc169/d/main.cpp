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
// const ll L_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

ll N;
// vector<int> A;

vector<pair<ll, ll>> prime_factor(ll n) {
  vector<pair<ll, ll>> v;

  for (ll p = 2; p * p <= n; ++p) {
    if (n % p != 0) {
      continue;
    }
    ll num = 0;
    while (n % p == 0) {
      ++num;
      n /= p;
    }
    v.push_back(make_pair(p, num));
  }

  if (n != 1) {
    v.push_back(make_pair(n, 1));
  }

  return v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  // A.resize(N);
  // for (int i = 0; i < N; i++) {
  //   int tmp;
  //   cin >> tmp;
  //   A[i] = tmp;
  // }

  ll cnt = 0;
  auto v = prime_factor(N);
  for (ll i = 0; i < v.size(); i++) {
    ll sum = 0;
    ll j = 1;
    while (sum < v[i].second) {
      cnt++;
      sum += j;
      j++;
    }
    if (sum != v[i].second) {
      cnt--;
    }
  }

  cout << cnt << endl;
  return 0;
}
