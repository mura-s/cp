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

int N, M;
vector<int> a, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  a.resize(M);
  b.resize(M);
  rep(i, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  int ans = 0;
  rep(i, M) {
    uf_tree ut(N);
    rep(j, M) {
      if (i != j) {
        ut.unite(a[j], b[j]);
      }
    }
    if (ut.size(0) != N) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
