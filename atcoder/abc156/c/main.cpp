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
const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int N;
vector<int> X;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  X.resize(N);
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    X[i] = tmp;
  }

  int ans = INF;
  for (int i = 1; i <= 100; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      sum += ((X[j] - i) * (X[j] - i));
    }
    ans = min(ans, sum);
  }

  cout << ans << endl;
  return 0;
}
