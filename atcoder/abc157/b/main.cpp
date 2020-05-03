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
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int A[3][3];
int N;
bool B[3][3];
// vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int a;
      cin >> a;
      A[i][j] = a;
    }
  }
  cin >> N;
  for (int k = 0; k < N; k++) {
    int b;
    cin >> b;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (A[i][j] == b) {
          B[i][j] = true;
        }
      }
    }
  }

  if ((B[0][0] && B[0][1] && B[0][2]) || (B[1][0] && B[1][1] && B[1][2]) ||
      (B[2][0] && B[2][1] && B[2][2]) || (B[0][0] && B[1][0] && B[2][0]) ||
      (B[0][1] && B[1][1] && B[2][1]) || (B[0][2] && B[1][2] && B[2][2]) ||
      (B[0][0] && B[1][1] && B[2][2]) || (B[2][0] && B[1][1] && B[0][2])) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;
}
