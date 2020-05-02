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

vector<int> A;

int N, M, Q;
vector<int> a, b, c, d;
int ans;

void dfs(int depth, int v) {
  if (depth == N) {
    int sum = 0;
    for (int i = 0; i < Q; i++) {
      if (A[b[i]] - A[a[i]] == c[i]) {
        sum += d[i];
      }
    }
    ans = max(ans, sum);
    return;
  }
  for (int i = v; i <= M; i++) {
    A[depth] = i;
    dfs(depth + 1, i);
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> Q;
  a.resize(Q);
  b.resize(Q);
  c.resize(Q);
  d.resize(Q);
  for (int i = 0; i < Q; i++) {
    int ai, bi, ci, di;
    cin >> ai >> bi >> ci >> di;
    ai--;
    bi--;
    a[i] = ai;
    b[i] = bi;
    c[i] = ci;
    d[i] = di;
  }
  A.resize(N, 0);
  dfs(0, 1);
  cout << ans << endl;
  return 0;
}
