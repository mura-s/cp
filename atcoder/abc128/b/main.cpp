#include <algorithm>
#include <climits>
#include <cmath>
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

struct City {
  string S;
  int P;
  int idx;
};

bool cmp(const City &a, const City &b) {
  if (a.S == b.S) {
    return a.P > b.P;
  }
  return a.S < b.S;
}

int N;
vector<City> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    string s;
    int p;
    cin >> s >> p;
    v[i] = City{s, p, i + 1};
  }
  sort(v.begin(), v.end(), cmp);

  for (auto &e : v) {
    cout << e.idx << endl;
  }

  return 0;
}