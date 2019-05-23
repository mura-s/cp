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
// const ll MOD = 1000000007;
// const int INF = 2000000000;

ll N, C;
vector<ll> x, v;
vector<ll> x_rev, v_rev;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> C;
  x.resize(N + 1, 0);
  v.resize(N + 1, 0);
  x_rev.resize(N + 1, 0);
  v_rev.resize(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> x[i] >> v[i];
    x_rev[N - i + 1] = C - x[i];
    v_rev[N - i + 1] = v[i];
  }

  vector<ll> cum_calory(N + 1, 0);
  ll calory = 0;
  for (int i = 1; i <= N; i++) {
    cum_calory[i] = max(cum_calory[i - 1], calory + v[i] - x[i] + x[i - 1]);
    calory += (v[i] - x[i] + x[i - 1]);
  }

  vector<ll> rev_cum_calory(N + 1, 0);
  calory = 0;
  for (int i = 1; i <= N; i++) {
    rev_cum_calory[i] =
        max(rev_cum_calory[i - 1], calory + v_rev[i] - x_rev[i] + x_rev[i - 1]);
    calory += (v_rev[i] - x_rev[i] + x_rev[i - 1]);
  }

  ll ans = 0LL;
  for (int i = 1; i <= N; i++) {
    ans = max(ans, cum_calory[i]);
    ans = max(ans, rev_cum_calory[i]);
    ans = max(ans, cum_calory[i] - x[i] + rev_cum_calory[N - i]);
    ans = max(ans, cum_calory[N - i] - x_rev[i] + rev_cum_calory[i]);
  }

  cout << ans << endl;
  return 0;
}