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
vector<int> B;
map<int, int> mp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (mp.find(A[i]) == mp.end()) {
      B.push_back(A[i]);
    }
    mp[A[i]]++;
  }
  sort(B.begin(), B.end(), greater<int>());
  int m = B[0];

  for (int i = 0; i < N; i++) {
    if (A[i] == m && mp[A[i]] > 1) {
      cout << A[i] << endl;
    } else if (A[i] == m) {
      cout << B[1] << endl;
    } else {
      cout << m << endl;
    }
  }

  return 0;
}