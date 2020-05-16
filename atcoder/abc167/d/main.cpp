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

ll N, K;
vector<int> A;
map<ll, ll> mp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    tmp--;
    A[i] = tmp;
  }

  vector<ll> route;
  ll loop_begin = 0;
  ll loop_num = 0;
  ll pos = 0;
  ll cnt = 0;
  route.push_back(pos);
  mp[pos] = cnt;
  while (true) {
    pos = A[pos];
    cnt++;
    if (cnt == K) {
      cout << (pos + 1) << endl;
      return 0;
    }
    if (mp.find(pos) != mp.end()) {
      loop_begin = mp[pos];
      loop_num = cnt - loop_begin;
      break;
    }
    route.push_back(pos);
    mp[pos] = cnt;
  }

  ll ans_pos = (K - loop_begin) % loop_num;
  ll ans = route[loop_begin + ans_pos];
  cout << ans + 1 << endl;
  return 0;
}
