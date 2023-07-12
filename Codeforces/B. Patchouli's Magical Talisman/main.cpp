#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int get_it_even(int n) {
  int r = 0;
  while ((n & 1) != 1) {
    r++;
    n = n / 2;
  }
  return r;
}

vector<pair<int, int>> get_prime_factors(ll n) {
    vector<pair<int, int>> result;
    int r = 0;

    while (n % 2 == 0) {
        r++;
        n = n / 2;
    }

    if (r > 0)
        result.push_back({2, r});

    int sqn = sqrt(n);
    for (int i = 3; i <= sqn; i += 2) {
        r = 0;
        while (n % i == 0) {
            r++;
            n = n / i;
        }
        if (r > 0)
            result.push_back({i, r});
    }

    if (n > 2)
        result.push_back({(int)n, 1});

    return result;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;

  cin >> testcases;

  while (testcases--) {
    bool odd_found = false;
    int get_the_even = 100000;
    int evens = 0;
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] & 1)
        odd_found = true;
      else {
        evens++;
        int x = get_it_even(a[i]);
        get_the_even = x < get_the_even ? x : get_the_even;
        // std::cout << "get_the_even, x: " << get_the_even << ", " <<  x << std::endl;
      }
    }

    // std::cout << evens << ", " << odd_found << std::endl;
    if (odd_found && !evens)
      std::cout << 0 << std::endl;
    else if (odd_found && evens)
      std::cout << evens << std::endl;
    else if (evens)
      std::cout << evens + get_the_even - 1 << std::endl;
  }

  return 0;
}
