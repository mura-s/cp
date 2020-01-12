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
const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

int H, W;
bool S[21][21];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W;
  int cnt = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      if (c == '.') {
        S[i][j] = true;
        cnt++;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j]) {
        vector<vector<int>> dist(21, vector<int>(21, INF));
        dist[i][j] = 0;
        queue<pair<int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
          int h, w;
          tie(h, w) = q.front();
          q.pop();
          if (w > 0 && S[h][w - 1] && dist[h][w - 1] == INF) {
            q.emplace(h, w - 1);
            dist[h][w - 1] = dist[h][w] + 1;
            ans = max(ans, dist[h][w - 1]);
          }
          if (w < W - 1 && S[h][w + 1] && dist[h][w + 1] == INF) {
            q.emplace(h, w + 1);
            dist[h][w + 1] = dist[h][w] + 1;
            ans = max(ans, dist[h][w + 1]);
          }
          if (h > 0 && S[h - 1][w] && dist[h - 1][w] == INF) {
            q.emplace(h - 1, w);
            dist[h - 1][w] = dist[h][w] + 1;
            ans = max(ans, dist[h - 1][w]);
          }
          if (h < H - 1 && S[h + 1][w] && dist[h + 1][w] == INF) {
            q.emplace(h + 1, w);
            dist[h + 1][w] = dist[h][w] + 1;
            ans = max(ans, dist[h + 1][w]);
          }
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
