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

int N, M, K;
vector<int> friends;
vector<int> blocks;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> K;
  uf_tree ut(N);
  friends.resize(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ut.unite(a, b);
    friends[a]++;
    friends[b]++;
  }
  blocks.resize(N);
  for (int i = 0; i < K; i++) {
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    if (ut.same(c, d)) {
      blocks[c]++;
      blocks[d]++;
    }
  }

  for (int i = 0; i < N; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << ut.size(i) - 1 - friends[i] - blocks[i];
  }
  cout << endl;
  return 0;
}
