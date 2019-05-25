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

string N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N.size(); i++) {
    if (N[i] == '1') {
      cout << '9';
    } else {
      cout << '1';
    }
  }
  cout << endl;
  return 0;
}