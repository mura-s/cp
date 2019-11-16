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
string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> S;
  if (N % 2 != 0) {
    cout << "No" << endl;
    return 0;
  }

  bool ans = true;
  int h = N / 2;
  for (int i = 0; i < h; i++) {
    if (S[i] != S[h + i]) {
      ans = false;
      break;
    }
  }

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}