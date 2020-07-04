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
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

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

const int MAX_E = 100001;

struct edge {
  int u, v, cost;
};
bool comp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }

edge es[MAX_E];
int V, E;

vector<edge> edges;

// 最小全域木 (全域木のうち、その辺群の重みの総和が最小になる木)
// を求めるアルゴリズム
//
// 計算量: O(ElogV)
int kruskal() {
  sort(es, es + E, comp);
  uf_tree uf(V);
  int res = 0;
  for (int i = 0; i < E; i++) {
    edge e = es[i];
    if (!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
      edges.push_back(e);
    }
  }
  return res;
}

int K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> E >> K;
  rep(i, E) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    es[i] = edge{a, b, c};
  }

  int ans = kruskal();
  sort(edges.begin(), edges.end(), comp);
  reverse(edges.begin(), edges.end());
  rep(i, K - 1) { ans -= edges[i].cost; }
  cout << ans << endl;
  return 0;
}
