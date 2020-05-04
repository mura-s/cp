#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
map<string, int> mp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    string tmp;
    cin >> tmp;
    mp[tmp]++;
  }

  int m = 0;
  for (auto &e : mp) {
    m = max(m, e.second);
  }
  for (auto &e : mp) {
    if (e.second == m) {
      cout << e.first << endl;
    }
  }
  return 0;
}
