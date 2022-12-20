// Date: 20-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

bool ask(int prime) {
  string ans;
  cout << prime << endl;
  cin >> ans;
  return ans == "yes";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  vector<int> primes;
  for (int i = 2; i <= 50; i++) {
    bool is_prime = true;
    for (int j = 2; j < i; j++) {
      if (i % j == 0)
        is_prime = false;
    }
    if (is_prime)
      primes.push_back(i);
  }

  int cnt = 0;
  for (int i = 0; i < (int) primes.size(); i++) {
    if (ask(primes[i])) {
      cnt++;
    }
  }

  for (int i = 0; i < 4; i++) {
    if (ask(primes[i] * primes[i])) {
      cout << "composite" << endl;
      return 0;
    }
  }

  cout << (cnt <= 1 ? "prime" : "composite") << endl;

  return 0;
}
