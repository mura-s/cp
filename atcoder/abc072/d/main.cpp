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
// const ll MOD = 1000000007;
// const int INF = 2000000000;

int N;
vector<int> p;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  p.resize(N);
  for (int i = 0; i < N; i++) {
    int pi;
    cin >> pi;
    pi--;
    p[i] = pi;
  }

  int ans = 0;
  int i = 0;
  while (i < N) {
    if (i != p[i]) {
      i++;
      continue;
    }

    int num = 0;
    while (i < N && i == p[i]) {
      i++;
      num++;
    }

    if (num % 2 == 0) {
      ans += (num / 2);
    } else {
      ans += (num / 2) + 1;
    }
  }

  cout << ans << endl;
  return 0;
}