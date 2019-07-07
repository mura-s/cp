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
const ll MOD = 1e9 + 7;

const ll MAX_V = 100000;
vector<ll> g[MAX_V];
bool visit[MAX_V];

struct edge {
  ll to, idx;
};

ll N, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i < N - 1; i++) {
    ll ai, bi;
    cin >> ai >> bi;
    ai--;
    bi--;
    g[ai].push_back(bi);
    g[bi].push_back(ai);
  }

  ll ans = K;
  queue<edge> q;
  q.push(edge{0, 1});
  visit[0] = true;

  while (!q.empty()) {
    edge e = q.front();
    q.pop();

    ll num = 0;
    if (e.idx <= 2) {
      num = K - e.idx;
    } else {
      num = K - 2;
    }

    for (int i = 0; i < g[e.to].size(); i++) {
      ll to = g[e.to][i];
      if (visit[to]) {
        continue;
      }
      visit[to] = true;
      ans *= num;
      ans %= MOD;
      q.push(edge{to, e.idx + 1});
      num--;
    }
  }

  cout << ans << endl;
  return 0;
}