// time-limit:  1000
// problem-url: https://codeforces.com/contest/770/problem/A
// submission:  https://codeforces.com/contest/770/submission/150621763

#include <iostream>
using namespace std;

int main() {
  // all Latin letters
  char letters[26];
  for (int i = 0; i < 26; i++)
    letters[i] = 0x61 + i;

  int n, k;
  cin >> n >> k;


  string password;
  // no randomization, take the first k letters
  string pwdletters = string(letters).substr(0, k);
  for (int i = 0; i < int(n / k); i++)
    password = password.append(pwdletters);
  // complete the password to be n letters length
  password = password.append(string(letters).substr(0, n - password.length()));
  cout << password << endl;
  return 0;
}
