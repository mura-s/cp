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
vector<ll> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  a.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  ll sum1 = a[0];
  for (int i = 1; i < N; i++) {
    sum1 ^= a[i];
  }
  ll sum2 = a[0] ^ a[0];
  for (int k = 0; k < 2; k++) {
    for (int i = 1; i < N; i++) {
      sum2 ^= a[i];
    }
  }

  if (sum1 == sum2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}