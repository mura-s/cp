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

int N, M;
vector<int> p;
vector<string> S;
bool found[100001];
bool ac[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  p.resize(M);
  S.resize(M);
  for (int i = 0; i < M; i++) {
    int pi;
    string Si;
    cin >> pi >> Si;
    pi--;
    if (Si == "AC") {
      found[pi] = true;
    }
    p[i] = pi;
    S[i] = Si;
  }

  int ans = 0;
  int penalty = 0;
  for (int i = 0; i < M; i++) {
    if (!ac[p[i]] && found[p[i]]) {
      if (S[i] == "AC") {
        ans++;
        ac[p[i]] = true;
      } else {
        penalty++;
      }
    }
  }

  cout << ans << " " << penalty << endl;
  return 0;
}