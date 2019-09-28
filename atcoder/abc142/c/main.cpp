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

bool cmp(const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; }

int N;
vector<pair<int, int>> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] = make_pair(i + 1, a);
  }

  sort(A.begin(), A.end(), cmp);
  for (int i = 0; i < N; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << A[i].first;
  }
  cout << endl;

  return 0;
}