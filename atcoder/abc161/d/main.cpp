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

ll K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> K;

  queue<ll> q;
  for (int i = 1; i < 10; i++) {
    q.push(i);
  }
  ll cnt = 0;
  ll ans = 0;
  while (cnt != K) {
    ll v = q.front();
    q.pop();
    ans = v;
    cnt++;
    if (v % 10 != 0) {
      q.push(v * 10 + (v % 10) - 1);
    }
    q.push(v * 10 + (v % 10));
    if ((v % 10) + 1 != 10) {
      q.push(v * 10 + (v % 10) + 1);
    }
  }
  cout << ans << endl;
  return 0;
}