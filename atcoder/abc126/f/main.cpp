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

int M, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> M >> K;

  if (M == 0) {
    if (K == 0) {
      cout << "0 0" << endl;
      return 0;
    }
  } else if (M == 1) {
    if (K == 0) {
      cout << "0 0 1 1" << endl;
      return 0;
    }
  } else {
    int lim = pow(2, M);
    if (K < lim) {
      vector<int> b(lim);
      for (int i = 0; i < lim; i++) {
        b[i] = i;
      }

      for (int i = 0; i < lim; i++) {
        if (i != K) {
          cout << b[i] << " ";
        }
      }
      cout << K << " ";
      for (int i = lim - 1; i >= 0; i--) {
        if (i != K) {
          cout << b[i] << " ";
        }
      }
      cout << K << endl;

      return 0;
    }
  }

  cout << "-1" << endl;
  return 0;
}