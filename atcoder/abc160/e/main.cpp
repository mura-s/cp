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

ll X, Y, A, B, C;
vector<ll> p, q, r;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> X >> Y >> A >> B >> C;
  p.resize(A);
  for (int i = 0; i < A; i++) {
    int tmp;
    cin >> tmp;
    p[i] = tmp;
  }
  q.resize(B);
  for (int i = 0; i < B; i++) {
    int tmp;
    cin >> tmp;
    q[i] = tmp;
  }
  r.resize(C);
  for (int i = 0; i < C; i++) {
    int tmp;
    cin >> tmp;
    r[i] = tmp;
  }
  sort(p.begin(), p.end(), greater<ll>());
  sort(q.begin(), q.end(), greater<ll>());

  priority_queue<ll, vector<ll>, greater<ll>> q_p;
  priority_queue<ll, vector<ll>, greater<ll>> q_q;
  for (int i = 0; i < X; i++) {
    q_p.push(p[i]);
  }
  for (int i = 0; i < Y; i++) {
    q_q.push(q[i]);
  }

  for (int i = 0; i < C; i++) {
    ll p_min = q_p.top();
    q_p.pop();
    ll q_min = q_q.top();
    q_q.pop();

    if (p_min < q_min && p_min < r[i]) {
      q_p.push(r[i]);
      q_q.push(q_min);
    } else if (q_min <= p_min && q_min < r[i]) {
      q_p.push(p_min);
      q_q.push(r[i]);
    } else {
      q_p.push(p_min);
      q_q.push(q_min);
    }
  }

  ll ans = 0;
  while (!q_p.empty()) {
    ll p_min = q_p.top();
    q_p.pop();
    ans += p_min;
  }
  while (!q_q.empty()) {
    ll q_min = q_q.top();
    q_q.pop();
    ans += q_min;
  }

  cout << ans << endl;
  return 0;
}
