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

const int INF = 2147483647;
// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;

// セグメント木による RMQ (Range Minimum Query) の実装
// RMQ以外にする場合は、minの部分を全て他の関数に置換する
//
// 計算量
// - 初期化: O(nlogn)
//   - O(n)でも実装できるが、O(nlogn)の実装になっている
//   - init後にupdateで初期化
// - update: O(logn)
// - query: O(logn)

const int MAX_N = 1 << 17;

// セグメント木を持つグローバル配列
int n;
int dat[2 * MAX_N - 1];

// 初期化
void init(int n_) {
  // 簡単のため、要素数を2のべき乗に
  n = 1;
  while (n < n_) {
    n *= 2;
  }

  // すべての値をINFに
  for (int i = 0; i < 2 * n - 1; i++) {
    dat[i] = INF;
  }
}

// k番目の値 (0-indexed) をaに変更
void update(int k, int a) {
  // 葉の節点
  k += n - 1;
  dat[k] = a;
  // 登りながら更新
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

// [a, b) の最小値を求める
// 後ろのほうの引数は、計算の簡単のための引数。
// kは節点の番号、l, rはその節点が [l, r) に対応づいていることを表す。
// したがって、外からは query(a, b, 0, 0, n) として呼ぶ。
int query(int a, int b, int k, int l, int r) {
  // [a, b) と [l, r) が交差しなければ INF
  if (r <= a || b <= l) {
    return INF;
  }

  // [a, b) が [l, r) を完全に含んでいれば、この節点の値
  if (a <= l && r <= b) {
    return dat[k];
  } else {
    // そうでなければ、2つの子の最小値
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
}

int n_, q;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n_ >> q;
  init(n_);

  for (int i = 0; i < q; i++) {
    int com, x, y;
    cin >> com >> x >> y;

    if (com == 0) {
      update(x, y);
    } else {
      cout << query(x, y + 1, 0, 0, n) << endl;
    }
  }
  return 0;
}