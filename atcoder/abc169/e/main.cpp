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
// const ll L_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

ll N;
vector<ll> A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  B.resize(N);
  for (int i = 0; i < N; i++) {
    ll ai, bi;
    cin >> ai >> bi;
    A[i] = ai;
    B[i] = bi;
  }

  int ans = 0;
  cout << ans << endl;
  return 0;
}
