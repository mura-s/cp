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
vector<int> d;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  d.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> d[i];
  }
  sort(d.begin(), d.end());

  int v1 = d[N / 2 - 1];
  int v2 = d[N / 2];

  cout << v2 - v1 << endl;
  return 0;
}