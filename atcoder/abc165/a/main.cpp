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

int K;
int A, B;
// vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> K >> A >> B;
  // A.resize(N);
  // for (int i = 0; i < N; i++) {
  //   int tmp;
  //   cin >> tmp;
  //   A[i] = tmp;
  // }

  int k = K;
  int i = 1;
  bool ok = false;
  while (k <= B) {
    if (A <= k && k <= B) {
      ok = true;
      break;
    }
    k = K * i;
    i++;
  }

  if (ok) {
    cout << "OK" << endl;
  } else {
    cout << "NG" << endl;
  }
  return 0;
}
