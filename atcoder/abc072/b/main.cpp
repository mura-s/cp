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

string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;

  string ans = "";
  for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0) {
      ans += s[i];
    }
  }

  cout << ans << endl;
  return 0;
}