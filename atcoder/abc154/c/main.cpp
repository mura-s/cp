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
set<int> A;
// vector<int> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    if (A.find(tmp) != A.end()) {
      cout << "NO" << endl;
      return 0;
    }
    A.insert(tmp);
  }

  cout << "YES" << endl;
  return 0;
}
