#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

// 素因数分解
// 素数の値と個数のpairのvectorを返す
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
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll M = 48;
  vector<pair<ll, ll>> primes = prime_factor(M);

  for (auto &e : primes) {
    cout << e.first << " " << e.second << endl;
  }
  return 0;
}