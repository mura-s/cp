#include <algorithm>
#include <climits>
#include <cmath>
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

int Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> Q;

  priority_queue<ll> que_l;
  priority_queue<ll, vector<ll>, greater<ll>> que_r;
  ll b_sum = 0;
  ll l_sum = 0, r_sum = 0;

  for (int i = 0; i < Q; i++) {
    int q;
    cin >> q;
    if (q == 1) {
      // update
      int a, b;
      cin >> a >> b;
      b_sum += b;
      if (que_l.empty() || a <= que_l.top()) {
        que_l.push(a);
        l_sum += a;
        if (que_l.size() > que_r.size() + 1) {
          ll t = que_l.top();
          que_l.pop();
          que_r.push(t);
          l_sum -= t;
          r_sum += t;
        }
      } else {
        que_r.push(a);
        r_sum += a;
        if (que_r.size() > que_l.size()) {
          ll t = que_r.top();
          que_r.pop();
          que_l.push(t);
          r_sum -= t;
          l_sum += t;
        }
      }
    } else {
      // print
      ll x = que_l.top();
      cout << x << " ";
      cout << b_sum + (x * (ll)que_l.size() - l_sum) + (r_sum - x * (ll)que_r.size());
      cout << endl;
    }
  }

  return 0;
}