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

int N;
// vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  // A.resize(N);
  // for (int i = 0; i < N; i++) {
  //   int tmp;
  //   cin >> tmp;
  //   A[i] = tmp;
  // }

  int ans = N % 10;
  if (ans == 2 || ans == 4 || ans == 5 || ans == 7 || ans == 9) {
    cout << "hon" << endl;
  } else if (ans == 0 || ans == 1 || ans == 6 || ans == 8) {
    cout << "pon" << endl;
  } else if (ans == 3) {
    cout << "bon" << endl;
  }

  return 0;
}
