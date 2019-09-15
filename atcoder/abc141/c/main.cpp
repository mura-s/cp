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

int N, K, Q;
vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K >> Q;
  A.resize(Q);
  for (int i = 0; i < Q; i++) {
    cin >> A[i];
    A[i]--;
  }

  vector<int> sum(N, 0);
  for (int i = 0; i < Q; i++) {
    sum[A[i]]++;
  }

  for (int i = 0; i < N; i++) {
    if (K - Q + sum[i] > 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}