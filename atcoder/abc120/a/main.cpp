#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int A, B, C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> C;

  if (A * C <= B) {
    cout << C << endl;
  } else {
    cout << B / A << endl;
  }

  return 0;
}