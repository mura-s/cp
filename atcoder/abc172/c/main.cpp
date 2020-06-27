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

ll N, M, K;
vector<ll> A, B;
vector<ll> sumA, sumB;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> K;
  A.resize(N);
  B.resize(M);
  rep(i, N) { cin >> A[i]; }
  rep(i, M) { cin >> B[i]; }

  sumA.resize(N + 1, 0);
  rep(i, N) { sumA[i + 1] = sumA[i] + A[i]; }
  sumB.resize(M + 1, 0);
  rep(i, M) { sumB[i + 1] = sumB[i] + B[i]; }

  ll ans = 0;
  for (int i = 0; i <= N; i++) {
    if (sumA[i] > K) {
      continue;
    }
    ll num = upper_bound(sumB.begin(), sumB.end(), K - sumA[i]) - sumB.begin();
    ans = max(ans, i + num - 1);
  }
  cout << ans << endl;
  return 0;
}
