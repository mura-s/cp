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

int N, K;
string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  cin >> S;
  K--;

  string ans = "";
  for (int i = 0; i < N; i++) {
    if (i == K) {
      if (S[i] == 'A') {
        ans += "a";
      } else if (S[i] == 'B') {
        ans += "b";
      } else {
        ans += "c";
      }
    } else {
      ans += S[i];
    }
  }

  cout << ans << endl;
  return 0;
}