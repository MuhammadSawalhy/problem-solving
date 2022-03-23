// time-limit:  1000
// problem-url: https://codeforces.com/contest/791/problem/A
// submission:  https://codeforces.com/contest/791/submission/150591450

#include <iostream>
#include <math.h>

int main() {
  float a, b;

  std::cin >> a;
  std::cin >> b;

  float years = log(a / b) / log(2.0 / 3.0);
  // add this to avoid float point errors
  years += 0.0001;
  // nearest integer greater than the current value
  years = floor(years) + 1;

  std::cout << years << std::endl;
  return 0;
}
