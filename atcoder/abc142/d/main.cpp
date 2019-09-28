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

vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) {
        res.push_back(n / i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}

bool is_prime(ll x) {
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

ll A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B;

  vector<ll> a_divs = divisor(A);
  vector<ll> b_divs = divisor(B);
  vector<ll> com_divs;
  int i = 0, j = 0;
  while (i < a_divs.size() && j < b_divs.size()) {
    if (a_divs[i] == b_divs[j]) {
      com_divs.push_back(a_divs[i]);
      i++;
      j++;
    } else if (a_divs[i] < b_divs[j]) {
      i++;
    } else if (a_divs[i] > b_divs[j]) {
      j++;
    }
  }
  ll ans = 0;
  for (auto &e : com_divs) {
    if (is_prime(e)) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}