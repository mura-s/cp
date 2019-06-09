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
const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int N;
vector<int> W;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  W.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> W[i];
  }

  int ans = INF;
  for (int i = 1; i < N; i++) {
    int S1 = 0, S2 = 0;
    for (int j = 0; j < i; j++) {
      S1 += W[j];
    }
    for (int j = i; j < N; j++) {
      S2 += W[j];
    }
    ans = min(ans, abs(S2 - S1));
  }

  cout << ans << endl;
  return 0;
}