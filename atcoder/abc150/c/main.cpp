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

int N;
vector<int> P, Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  P.resize(N);
  for (int i = 0; i < N; i++) {
    int pi;
    cin >> pi;
    P[i] = pi;
  }
  Q.resize(N);
  for (int i = 0; i < N; i++) {
    int qi;
    cin >> qi;
    Q[i] = qi;
  }

  vector<int> s_P = P;
  sort(s_P.begin(), s_P.end());
  vector<int> s_Q = Q;
  sort(s_Q.begin(), s_Q.end());

  int a = 0;
  do {
    a++;
    bool f = true;
    for (int i = 0; i < P.size(); i++) {
      if (P[i] != s_P[i]) {
        f = false;
        break;
      }
    }
    if (f) {
      break;
    }
  } while (next_permutation(s_P.begin(), s_P.end()));

  int b = 0;
  do {
    b++;
    bool f = true;
    for (int i = 0; i < Q.size(); i++) {
      if (Q[i] != s_Q[i]) {
        f = false;
        break;
      }
    }
    if (f) {
      break;
    }
  } while (next_permutation(s_Q.begin(), s_Q.end()));

  int ans = abs(a - b);
  cout << ans << endl;
  return 0;
}