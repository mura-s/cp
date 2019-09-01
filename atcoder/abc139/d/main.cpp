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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;

  // vector<ll> v;
  // for (ll i = 1; i <= 13; i++) {
  //   v.push_back(i);
  // }
  // do {
  //   int ans = 0;
  //   for (int i = 1; i <= 13; i++) {
  //     ans += (i % v[i - 1]);
  //   }
  //   if (ans == 78) {
  //     for (auto &e : v) {
  //       cout << e << " ";
  //     }
  //     cout << endl;
  //   }
  // } while (next_permutation(v.begin(), v.end()));

  if (N == 1) {
    cout << 0 << endl;
  } else {
    cout << (N - 1) * N / 2 << endl;
  }

  return 0;
}