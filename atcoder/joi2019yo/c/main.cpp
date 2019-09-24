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

  int ans = 0;
  int i = 0;
  while (i < N - 1) {
    if (S[i] == 'O' && S[i + 1] == 'X') {
      ans++;
      i += 2;
    } else if (S[i] == 'X' && S[i + 1] == 'O') {
      ans++;
      i += 2;
    } else {
      i++;
    }
  }

  cout << ans << endl;
  return 0;
}