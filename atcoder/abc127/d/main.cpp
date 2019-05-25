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

struct Card {
  ll n, cnt;
};

bool cmp(const Card &a, const Card &b) {
  if (a.n == b.n) {
    return a.cnt > b.cnt;
  }
  return a.n > b.n;
}

ll N, M;
vector<Card> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  v.resize(N + M);
  for (int i = 0; i < N; i++) {
    ll ai;
    cin >> ai;
    v[i] = Card{ai, 1};
  }
  for (int i = 0; i < M; i++) {
    ll bi, ci;
    cin >> bi >> ci;
    v[N + i] = Card{ci, bi};
  }

  sort(v.begin(), v.end(), cmp);

  ll ans = 0;
  ll cnt = 0;
  for (int i = 0; i < N + M; i++) {
    if (cnt + v[i].cnt == N) {
      ans += (v[i].n * v[i].cnt);
      break;
    } else if (cnt + v[i].cnt > N) {
      ll c = N - cnt;
      ans += (v[i].n * c);
      break;
    } else {
      ans += (v[i].n * v[i].cnt);
      cnt += v[i].cnt;
    }
  }

  cout << ans << endl;
  return 0;
}