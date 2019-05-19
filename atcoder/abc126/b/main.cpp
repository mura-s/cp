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

string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;

  string A = S.substr(0, 2);
  string B = S.substr(2, 4);

  if ("01" <= A && A <= "12" && "01" <= B && B <= "12") {
    cout << "AMBIGUOUS" << endl;
  } else if ("01" <= A && A <= "12") {
    cout << "MMYY" << endl;
  } else if ("01" <= B && B <= "12") {
    cout << "YYMM" << endl;
  } else {
    cout << "NA" << endl;
  }

  return 0;
}