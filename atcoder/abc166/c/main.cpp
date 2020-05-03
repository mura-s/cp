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

int N, M;
vector<int> H;
vector<int> A, B;
vector<bool> good;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  H.resize(N);
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    H[i] = tmp;
  }
  A.resize(M);
  B.resize(M);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    A[i] = a;
    B[i] = b;
  }

  good.resize(N, true);
  for (int i = 0; i < M; i++) {
    if (H[A[i]] == H[B[i]]) {
      good[A[i]] = false;
      good[B[i]] = false;
    } else if (H[A[i]] < H[B[i]]) {
      good[A[i]] = false;
    } else if (H[A[i]] > H[B[i]]) {
      good[B[i]] = false;
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (good[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
