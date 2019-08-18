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

const int MAX_V = 200005;
vector<int> g[MAX_V];

int N, Q;
map<int, long> mp;

long point[MAX_V];

void dfs(int v, long cur_point) {
  if (point[v] != 0) {
    return;
  }
  long tmp = mp[v];
  point[v] = cur_point + tmp;

  for (auto next_v : g[v]) {
    dfs(next_v, cur_point + tmp);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
  }
  for (int i = 0; i < Q; i++) {
    int p;
    long x;
    cin >> p >> x;
    p--;
    mp[p] += x;
  }

  dfs(0, 0);
  for (int i = 0; i < N; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << point[i];
  }
  cout << endl;
  return 0;
}