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

const int A_MAX = 100001;

int N;
int A[A_MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int ai;
    cin >> ai;
    A[ai]++;
  }

  int ans = 0;

  for (int i = 2; i < A_MAX; i++) {
    ans = max(ans, A[i - 2] + A[i - 1] + A[i]);
  }

  cout << ans << endl;
  return 0;
}