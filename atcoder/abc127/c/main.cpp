#include <algorithm>
#include <climits>
#include <cmath>
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
// const ll MOD = 1000000007;
// const int INF = 2000000000;

int N, M;
// vector<int> L, R;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  vector<int> sum(N + 1, 0);
  for (int i = 0; i < M; i++) {
    int li, ri;
    cin >> li >> ri;
    li--;
    ri--;
    sum[li]++;
    sum[ri + 1]--;
  }

  vector<int> cum(N + 1, 0);
  cum[0] = sum[0];
  for (int i = 1; i <= N; i++) {
    cum[i] = cum[i - 1] + sum[i];
  }

  int ans = 0;
  for (int i = 0; i <= N; i++) {
    if (cum[i] == M) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}