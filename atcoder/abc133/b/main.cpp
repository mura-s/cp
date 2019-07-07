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

int N, D;
vector<vector<int>> X;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> D;
  X = vector<vector<int>>(N, vector<int>(D, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      cin >> X[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int sum = 0;
      for (int k = 0; k < D; k++) {
        sum += pow(abs(X[i][k] - X[j][k]), 2);
      }
      double root = sqrt(sum);
      if (ceil(root) == floor(root)) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}