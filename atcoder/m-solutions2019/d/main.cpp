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

const int MAX_V = 10000;

vector<int> g[MAX_V];

int N;
vector<int> c;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  c.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int ai, bi;
    cin >> ai >> bi;
    ai--;
    bi--;
    g[ai].push_back(bi);
    g[bi].push_back(ai);
  }
  for (int i = 0; i < N; i++) {
    cin >> c[i];
  }
  sort(c.begin(), c.end(), greater<int>());

  int sum = 0;
  vector<int> vals(N, 0);
  int cur = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (vals[v] != 0) {
      continue;
    }
    vals[v] = c[cur];
    cur++;
    sum += vals[v];
    for (int i = 0; i < g[v].size(); i++) {
      q.push(g[v][i]);
    }
  }

  cout << sum - c[0] << endl;
  for (int i = 0; i < N; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << vals[i];
  }
  cout << endl;
  return 0;
}