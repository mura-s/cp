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
vector<int> A;
vector<bool> sea;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sea.resize(N + 2, false);
  sea[0] = sea[N + 1] = true;
  for (int i = 0; i < N; i++) {
    sea[i + 1] = (A[i] == 0);
  }

  int current = 0;
  for (int i = 0; i < N + 1; i++) {
    if (!sea[i] && sea[i + 1]) {
      current++;
    }
  }

  vector<pair<int, int>> vec;
  for (int i = 0; i < N; i++) {
    if (A[i] > 0) {
      vec.push_back(make_pair(A[i], i + 1));
    }
  }
  sort(vec.begin(), vec.end());

  int ans = current;
  for (int i = 0; i < vec.size(); i++) {
    int idx = vec[i].second;
    sea[idx] = true;
    if (sea[idx - 1] && sea[idx + 1]) {
      current--;
    } else if (!sea[idx - 1] && !sea[idx + 1]) {
      current++;
    }

    if (i == N - 1 || vec[i].first != vec[i + 1].first) {
      ans = max(ans, current);
    }
  }

  cout << ans << endl;
  return 0;
}