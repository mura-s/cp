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

struct uf_tree {
  vector<int> par, sizes;
  uf_tree(int n) : par(n), sizes(n, 1) {
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
  }
  int find(int x) {
    if (x == par[x]) {
      return x;
    }
    return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    if (sizes[x] < sizes[y]) {
      swap(x, y);
    }
    par[y] = x;
    sizes[x] += sizes[y];
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return sizes[find(x)]; }
};

int N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  uf_tree uf(N);
  for (int i = 0; i < M; i++) {
    int xi, yi, zi;
    cin >> xi >> yi >> zi;
    xi--;
    yi--;
    uf.unite(xi, yi);
  }

  int ans = 0;
  set<int> st;
  for (int i = 0; i < N; i++) {
    int v = uf.find(i);
    if (st.find(v) == st.end()) {
      ans++;
      st.insert(v);
    }
  }

  cout << ans << endl;
  return 0;
}