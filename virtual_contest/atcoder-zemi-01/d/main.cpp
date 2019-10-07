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

ll N, K;
vector<ll> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  A.resize(N);
  map<ll, ll> mp;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    mp[A[i]]++;
  }

  int cnt = 0;
  priority_queue<ll> pq;
  for (auto &e : mp) {
    pq.push(e.second);
    cnt++;
  }

  int size = pq.size();
  int ans = 0;
  for (int i = 1; i <= size; i++) {
    int n = pq.top();
    pq.pop();
    if (i > K) {
      ans += n;
    }
  }

  cout << ans << endl;
  return 0;
}