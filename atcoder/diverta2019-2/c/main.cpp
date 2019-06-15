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

int N;
vector<int> A;
int p_num, m_num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] >= 0) {
      p_num++;
    } else {
      m_num++;
    }
  }
  sort(A.begin(), A.end());
  if (p_num == 0) {
    p_num++;
    m_num--;
  } else if (m_num == 0) {
    p_num--;
    m_num++;
  }

  int m = A[0];
  vector<int> x, y;
  for (int i = m_num; i < N - 1; i++) {
    x.push_back(m);
    y.push_back(A[i]);
    m -= A[i];
  }
  A[0] = m;
  m = A[N - 1];
  for (int i = 0; i < m_num; i++) {
    x.push_back(m);
    y.push_back(A[i]);
    m -= A[i];
  }

  cout << m << endl;
  for (int i = 0; i < N - 1; i++) {
    cout << x[i] << " " << y[i] << endl;
  }

  return 0;
}