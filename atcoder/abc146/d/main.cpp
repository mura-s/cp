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

const int MAX_V = 100001;
struct edge {
  int num, to;
};
vector<edge> g[MAX_V];

int ans[MAX_V];
int p_color[MAX_V];
int K;

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(edge{i, b});
    g[b].push_back(edge{i, a});
  }

  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    int color = 0;
    for (int i = 0; i < g[n].size(); i++) {
      int next = g[n][i].to;
      int num = g[n][i].num;
      if (ans[num] != 0) {
        continue;
      }
      color++;
      if (color == p_color[n]) {
        color++;
      }
      ans[num] = color;
      p_color[next] = color;
      K = max(K, color);
      q.push(next);
    }
  }

  cout << K << endl;
  for (int i = 0; i < N - 1; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}