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

ll N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  priority_queue<ll> pq;
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    pq.push(a);
  }

  for (int i = 0; i < M; i++) {
    ll a = pq.top();
    pq.pop();
    pq.push(a / 2);
  }

  ll ans = 0;
  while (!pq.empty()) {
    ll a = pq.top();
    pq.pop();
    ans += a;
  }

  cout << ans << endl;
  return 0;
}