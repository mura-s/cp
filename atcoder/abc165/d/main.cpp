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

ll A, B, N;
// vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> N;
  // A.resize(N);
  // for (int i = 0; i < N; i++) {
  //   int tmp;
  //   cin >> tmp;
  //   A[i] = tmp;
  // }

  ll ans = 0;
  if (N < B) {
    ans = (A * N / B) - (A * (N / B));
  } else {
    ans = (A * (B - 1) / B) - (A * ((B - 1) / B));
  }

  cout << ans << endl;
  return 0;
}
