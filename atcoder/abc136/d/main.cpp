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
int N;
vector<int> L, R;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;
  N = S.size();
  for (int i = 0; i < N; i++) {
    if (S[i] == 'R') {
      R.push_back(i);
    } else {
      L.push_back(i);
    }
  }

  vector<int> ans(N, 0);
  // Rについて
  int l_idx = 0;
  for (int i = 0; i < R.size(); i++) {
    int r_pos = R[i];
    int l_pos = L[l_idx];
    while (r_pos > l_pos) {
      l_idx++;
      l_pos = L[l_idx];
    }

    if ((l_pos - r_pos) % 2 == 0) {
      ans[l_pos]++;
    } else {
      ans[l_pos - 1]++;
    }
  }

  // Lについて
  int r_idx = R.size() - 1;
  for (int i = L.size() - 1; i >= 0; i--) {
    int l_pos = L[i];
    int r_pos = R[r_idx];
    while (r_pos > l_pos) {
      r_idx--;
      r_pos = R[r_idx];
    }

    if ((l_pos - r_pos) % 2 == 0) {
      ans[r_pos]++;
    } else {
      ans[r_pos + 1]++;
    }
  }

  for (int i = 0; i < N; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
  return 0;
}