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

int N, K;
string S;
vector<pair<char, int>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  cin >> S;
  for (int i = 0; i < N;) {
    char c = S[i];
    int cnt = 1;
    i++;
    while (i < N && S[i] == c) {
      cnt++;
      i++;
    }
    v.push_back(make_pair(c, cnt));
  }

  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    ans += (v[i].second - 1);
  }

  int cnt = 0;
  for (int i = 1; i < v.size() - 1; i += 2) {
    if (cnt < K) {
      ans += 2;
    }
    cnt++;
  }
  if (cnt < K && v.size() % 2 == 0) {
    ans++;
  }

  cout << ans << endl;
  return 0;
}