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
vector<int> B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  B.resize(N-1);
  for (int i = 0; i < N-1; i++) {
    cin >> B[i];
  }
  N--;

  int ans = B[0];
  for (int i = 0; i < N-1; i++) {
    ans += min(B[i], B[i+1]);
  }
  ans += B[N-1];

  cout << ans << endl;
  return 0;
}