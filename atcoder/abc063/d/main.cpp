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

ll N, A, B, DIFF;
vector<ll> h;

bool killed(ll cnt) {
  ll tmp_cnt = cnt;
  for (auto e : h) {
    e -= (B * cnt);
    if (e <= 0) {
      continue;
    }

    if (e % DIFF == 0) {
      tmp_cnt -= (e / DIFF);
    } else {
      tmp_cnt -= (e / DIFF + 1);
    }
  }
  if (tmp_cnt < 0) {
    return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> A >> B;
  DIFF = A - B;
  h.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  sort(h.begin(), h.end());

  ll l = 0, r = h[N - 1] + 1;
  while (r - l > 1) {
    ll mid = l + (r - l) / 2;
    if (killed(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << r << endl;
  return 0;
}