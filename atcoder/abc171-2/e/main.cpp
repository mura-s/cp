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
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LLP = pair<ll, ll>;

// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

int N;
vector<int> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  a.resize(N);
  rep(i, N) { cin >> a[i]; }

  int sum = 0;
  rep(i, N) { sum ^= a[i]; }

  rep(i, N) {
    if (i != 0) {
      cout << " ";
    }
    cout << (sum ^ a[i]);
  }
  cout << endl;
  return 0;
}
