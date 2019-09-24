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

int N, M;
vector<int> X, A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  X.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }
  cin >> M;
  A.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i];
    A[i]--;
  }

  for (int i = 0; i < M; i++) {
    int koma = A[i];
    if (koma == N - 1) {
      if (X[koma] < 2019) {
        X[koma]++;
      }
    } else {
      if (X[koma] + 1 != X[koma + 1]) {
        X[koma]++;
      }
    }
  }

  for (auto &e : X) {
    cout << e << endl;
  }
  return 0;
}