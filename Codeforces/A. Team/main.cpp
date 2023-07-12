// time-limit:  2000
// problem-url: https://codeforces.com/contest/791/problem/A
// submission:  https://codeforces.com/contest/231/submission/150592551

#include <iostream>

int main() {
  int n, solved = 0, views = 0, view;

  std::cin >> n;

  while (n) {
    views = 0;
    std::cin >> view;
    views += view;
    std::cin >> view;
    views += view;
    std::cin >> view;
    views += view;
    if (views > 1)
      solved++;

    n--;
  }

  std::cout << solved << std::endl;

  return 0;
}
