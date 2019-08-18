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

int a;
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> s;

  if (a >= 3200) {
    cout << s << endl;
  } else {
    cout << "red" << endl;
  }

  return 0;
}