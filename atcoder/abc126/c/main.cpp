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

int N, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;

  double ans = 0;
  for (int i = 1; i <= N; i++) {
    int num = 0;
    int v = i;
    while (v < K) {
      num++;
      v *= 2;
    }
    ans += pow(0.5, num);
  }

  cout << fixed << setprecision(10) << ans / N << endl;
  return 0;
}