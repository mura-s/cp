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
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

ll gcd(ll a, ll b) {
  if (a < b) {
    return gcd(b, a);
  }

  while (a % b != 0) {
    ll tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll N, M;
vector<ll> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  A.resize(N);
  rep(i, N) {
    cin >> A[i];
    A[i] /= 2;
  }

  vector<ll> B = A;
  ll cntTwo = 0;
  while (B[0] % 2 == 0) {
    cntTwo++;
    B[0] /= 2;
  }
  for (int i = 1; i < N; i++) {
    ll cnt = 0;
    while (B[i] % 2 == 0) {
      cnt++;
      B[i] /= 2;
    }
    if (cnt != cntTwo) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll l = A[0];
  for (int i = 1; i < N; i++) {
    l = lcm(l, A[i]);
  }

  ll ans = (M / l + 1) / 2;
  cout << ans << endl;
  return 0;
}
