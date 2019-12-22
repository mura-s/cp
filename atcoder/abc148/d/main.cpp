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

ll N;
vector<ll> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  a.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int num = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] == num + 1) {
      num++;
    }
  }

  if (num == 0) {
    cout << -1 << endl;
  } else {
    cout << N - num << endl;
  }
  return 0;
}