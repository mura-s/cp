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
vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  int ans = INF;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    int cnt = 0;
    while (A[i] % 2 == 0) {
      A[i] /= 2;
      cnt++;
    }
    ans = min(ans, cnt);
  }


  cout << ans << endl;
  return 0;
}