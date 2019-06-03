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
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int N, A, B, C, D;
string S;

bool solve() {
  int s_num = 0;
  for (int i = A + 1; i < D; i++) {
    if (S[i] == '#') {
      s_num++;
      if (s_num == 2) {
        return false;
      }
    } else {
      s_num = 0;
    }
  }

  if (C > D) {
    bool ok = false;
    int d_num = 0;
    for (int i = B - 1; i < D + 2; i++) {
      if (S[i] == '.') {
        d_num++;
        if (d_num == 3) {
          ok = true;
          break;
        }
      } else {
        d_num = 0;
      }
    }
    if (!ok) {
      return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> A >> B >> C >> D;
  cin >> S;
  A--;
  B--;
  C--;
  D--;

  if (solve()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}