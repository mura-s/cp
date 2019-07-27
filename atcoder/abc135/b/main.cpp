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
vector<int> p;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  p.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
  vector<int> sorted = p;
  sort(sorted.begin(), sorted.end());

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (p[i] != sorted[i]) {
      cnt++;
    }
  }

  if (cnt <= 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}