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
const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int N, M, X;
vector<int> C;
vector<vector<int>> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> X;
  C.resize(N);
  A.resize(N);
  for (int i = 0; i < N; i++) {
    int ci;
    cin >> ci;
    C[i] = ci;
    A[i].resize(M);
    for (int j = 0; j < M; j++) {
      int a;
      cin >> a;
      A[i][j] = a;
    }
  }

  int ans = INF;
  for (int i = 1; i < (1 << N); i++) {
    vector<int> points(M, 0);
    int cost = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        for (int k = 0; k < M; k++) {
          points[k] += A[j][k];
        }
        cost += C[j];
      }
    }

    bool ok = true;
    for (int j = 0; j < M; j++) {
      if (points[j] < X) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = min(ans, cost);
    }
  }

  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
