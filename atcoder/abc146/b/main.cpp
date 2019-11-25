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

  for (int i = 0; i < S.size(); i++) {
    char c = S[i] + N;
    if (c > 'Z') {
      c = c - 26;
      cout << c;
    } else {
      cout << c;
    }
  }
  cout << endl;

  return 0;
}