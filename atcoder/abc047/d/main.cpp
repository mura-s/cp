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
const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int N, T;
vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> T;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int pat = 0;
  int max_diff = 0;
  int min_v = INF;
  for (int i = 0; i < N; i++) {
    if (A[i] < min_v) {
      min_v = A[i];
    } else {
      int diff = A[i] - min_v;
      if (max_diff == diff) {
        pat++;
      } else if (diff > max_diff) {
        pat = 1;
        max_diff = diff;
      }
    }
  }

  cout << pat << endl;
  return 0;
}