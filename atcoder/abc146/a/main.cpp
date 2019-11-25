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

string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;

  int ans = 0;
  if (S == "SUN") {
    ans = 7;
  } else if (S == "MON") {
    ans = 6;
  } else if (S == "TUE") {
    ans = 5;
  } else if (S == "WED") {
    ans = 4;
  } else if (S == "THU") {
    ans = 3;
  } else if (S == "FRI") {
    ans = 2;
  } else if (S == "SAT") {
    ans = 1;
  }

  cout << ans << endl;
  return 0;
}