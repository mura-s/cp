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
vector<int> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  a.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  int M = 0;
  vector<int> b(N + 1, 0);

  for (int i = N; i >= 1; i--) {
    int sum = 0;
    int cur = i + i;
    while (cur <= N) {
      sum += b[cur];
      cur += i;
    }

    if (sum % 2 != a[i]) {
      b[i] = 1;
      M++;
    }
  }

  cout << M << endl;
  for (int i = 1; i <= N; i++) {
    if (b[i] == 1) {
      cout << i << endl;
    }
  }
  return 0;
}