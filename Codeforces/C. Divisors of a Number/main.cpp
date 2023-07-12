#include <bits/stdc++.h>

using namespace std;

int count_divisible_nums(int n, vector<int> nums) {
  int c = 1;
  int cnt = 0;

  while (c < 1 << nums.size()) {
    char sign = __builtin_popcountll(c) % 2 ? 1 : -1;
    int d = 1;
    for (int i = 0; i < nums.size(); i++) {
      if (c & 1 << i)
        d = lcm(d, nums[i]);
    }

    cnt += sign * n / d;
    c++;
  }

  return cnt;
}

int main(int argc, char *argv[]) {
  int t;
  std::cin >> t;

  while (t--) {
    int n, c;
    std::cin >> n >> c;
    vector<int> nums(c);
    for (int &i : nums)
      cin >> i;
    std::cout << count_divisible_nums(n, nums) << std::endl;
  }

  return 0;
}
