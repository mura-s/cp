#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
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
vector<int> V;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  V.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }

  int ans = 0;
  for (int i = 0; i <= K; i++) {
    for (int j = 0; j <= K; j++) {
      int sum = 0;
      if (i + j > min(N, K)) {
        continue;
      }
      int r = min(i + j, K - i - j);

      priority_queue<int, vector<int>, greater<int>> pq;
      for (int k = 0; k < i; k++) {
        sum += V[k];
        pq.push(V[k]);
      }
      for (int k = 0; k < j; k++) {
        sum += V[N - k - 1];
        pq.push(V[N - k - 1]);
      }

      for (int k = 0; k < r; k++) {
        int n = pq.top();
        pq.pop();
        if (n < 0) {
          sum -= n;
        }
      }

      ans = max(ans, sum);
    }
  }

  cout << ans << endl;
  return 0;
}