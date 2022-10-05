#include <bits/stdc++.h>
#include "debug.hpp"

using namespace std;

// clang-format off

class big_int {
public:
  vector<int> digits;

  big_int(unsigned long long value) { set_value(value); }

  template <typename RandomIt>
  big_int(RandomIt begin, RandomIt end) {
    digits.assign(begin, end);
  }

  void set_value(unsigned long long value) {
    while (value) {
      digits.push_back(value % 10);
      value /= 10;
    }
  }
};

ostream &operator<<(ostream &os, const big_int &bi) {
  for (size_t i = 0; i < bi.digits.size(); i++)
    os << bi.digits[bi.digits.size() - 1 - i];
  os << endl;
  return os;
}

// clang-format on

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  deque<unsigned long long> qu;
  vector<unsigned long long> ve;
  for (size_t i = 0; i < s.size(); i++)
    qu.push_back(stoi(string(s, i, 1))), ve.push_back(qu.back());
  debug(qu);
  
  big_int bi(qu.begin(), qu.end());
  cout << bi << endl;
  return 0;
}
