// time-limit:  1000
// problem-url: https://codeforces.com/contest/732/problem/A
// submission:  https://codeforces.com/contest/732/submission/150594321

#include <iostream>
using namespace std;

int main() {
  bool found = 0;
  int k, r, shovels = 0;

  cin >> k >> r;

  while (!found) {
    shovels++;
    if ((k * shovels) % 10 == 0 || (k * shovels - r) % 10 == 0)
      found = true;
  }

  cout << shovels << endl;

  return 0;
}
