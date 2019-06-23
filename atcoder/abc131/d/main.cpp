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
vector<pair<int, int>> p_vec;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  p_vec.resize(N);
  for (int i = 0; i < N; i++) {
    int ai, bi;
    cin >> ai >> bi;
    p_vec[i] = make_pair(bi, ai);
  }
  sort(p_vec.begin(), p_vec.end());

  bool ok = true;
  int cur = 0;
  for (int i = 0; i < N; i++) {
    cur += p_vec[i].second;
    if (cur > p_vec[i].first) {
      ok = false;
      break;
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}