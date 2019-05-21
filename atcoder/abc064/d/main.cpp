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

int N;
string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> S;

  string prefix = "";
  string suffix = "";

  int c = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '(') {
      c++;
    } else {
      if (c == 0) {
        prefix += "(";
      } else {
        c--;
      }
    }
  }

  c = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (S[i] == ')') {
      c++;
    } else {
      if (c == 0) {
        suffix += ")";
      } else {
        c--;
      }
    }
  }

  cout << prefix << S << suffix << endl;
  return 0;
}