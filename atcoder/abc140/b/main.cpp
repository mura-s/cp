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

int N;
vector<int> A, B, C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }
  B.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  C.resize(N - 1);
  for (int i = 0; i < N - 1; i++) {
    cin >> C[i];
  }

  int ans = 0;
  int pos = -10;
  for (int i = 0; i < N; i++) {
    int p = A[i];
    ans += B[p];
    if (pos + 1 == p) {
      ans += C[pos];
    }
    pos = p;
  }

  cout << ans << endl;
  return 0;
}