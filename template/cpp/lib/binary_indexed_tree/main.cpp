#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = (1 << 30) - 1;
// const ll L_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

const int MAX_N = 100000;

// 数列に対し, ある要素に値を加える操作と,
// 区間和を求める操作をそれぞれ対数時間で行うことが出来るデータ構造。
// 計算量: O(logN)
//
// sum: 区間[1, i]の合計を求める。
// add: 要素iに値xを加える。

// [1, n]
int bit[MAX_N + 1];
int n;
int q;

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  while (q > 0) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      add(x, y);
    } else {
      cout << sum(y) - sum(x - 1) << endl;
    }
    q--;
  }
  return 0;
}
