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

int N;
vector<string> S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  S.resize(N);
  rep(i, N) { cin >> S[i]; }

  int c0 = 0;
  int c1 = 0;
  int c2 = 0;
  int c3 = 0;

  rep(i, N) {
    if (S[i] == "AC") {
      c0++;
    } else if (S[i] == "WA") {
      c1++;
    } else if (S[i] == "TLE") {
      c2++;
    } else {
      c3++;
    }
  }

  cout << "AC x " << c0 << endl;
  cout << "WA x " << c1 << endl;
  cout << "TLE x " << c2 << endl;
  cout << "RE x " << c3 << endl;
  return 0;
}
