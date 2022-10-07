#include <iostream>
#include <vector>

using namespace std;

int gen(int a, int b) { return a + rand() % (b - a + 1); }

class bigint {
public:
  vector<int> digits;

  bigint(unsigned long long value = 0) { set_value(value); }

  bigint(string s) {
    digits.resize(s.size());
    for (int i = (int)s.size() - 1; i >= 0; i--) {
      digits[i] = s[(int)s.size() - 1 - i] - '0';
    }
  }

  template <typename RandomIt> bigint(RandomIt begin, RandomIt end) {
    digits.assign(begin, end);
  }

  void set_value(unsigned long long value) {
    digits.clear();
    while (value) {
      digits.push_back(value % 10);
      value /= 10;
    }
  }

  int size() const { return digits.size(); }

  int &operator[](int i) { return digits[i]; }

  int operator[](int i) const { return digits[i]; }

  void trim() {
    while (digits.back() == 0)
      digits.pop_back();
  }

  bigint &operator*=(const bigint &rhs) {
    vector<int> res(size() + rhs.size() + 1);
    for (int i = 0; i < size(); i++) {
      for (int j = 0; j < rhs.size(); j++) {
        res[i + j] += digits[i] * rhs[j];
      }
    }
    for (int i = 0; i < res.size() - 1; i++) {
      res[i + 1] += res[i] / 10;
      res[i] %= 10;
    }
    digits = res;
    trim();
    return *this;
  }

  bigint &operator+=(const bigint &rhs) {
    digits.resize(max(size(), rhs.size()) + 1);
    for (int i = 0; i < rhs.size(); i++) {
      digits[i] += rhs[i];
      digits[i + 1] += digits[i] / 10;
      digits[i] %= 10;
    }
    trim();
    return *this;
  }

  friend bigint operator+(const bigint &lhs, const bigint &rhs) {
    bigint res = lhs;
    res.digits.resize(max(rhs.size(), lhs.size()) + 1);
    for (int i = 0; i < (int)res.size() - 1; i++) {
      res[i] += rhs[i];
      res[i + 1] += res[i] / 10;
      res[i] %= 10;
    }
    res.trim();
    return res;
  }

  friend bigint operator*(const bigint &lhs, const bigint &rhs) {
    bigint res;
    res.digits.resize(rhs.size() + lhs.size() + 1);
    for (int i = 0; i < lhs.size(); i++) {
      for (int j = 0; j < rhs.size(); j++) {
        res[i + j] += lhs[i] * rhs[j];
      }
    }
    for (int i = 0; i < res.size() - 1; i++) {
      res[i + 1] += res[i] / 10;
      res[i] %= 10;
    }
    res.trim();
    return res;
  }

  friend bool operator==(const bigint &lhs, const bigint &rhs) {
    return lhs.digits == rhs.digits;
  }

  friend bool operator>(const bigint &lhs, const bigint &rhs) {
    if (lhs.size() != rhs.size())
      return lhs.size() > rhs.size();
    for (int i = lhs.size() - 1; i >= 0; i--) {
      if (lhs[i] > rhs[i])
        return true;
    }
    return false;
  }

  friend bool operator>=(const bigint &lhs, const bigint &rhs) {
    if (lhs.size() != rhs.size())
      return lhs.size() > rhs.size();
    for (int i = lhs.size() - 1; i >= 0; i--) {
      if (lhs[i] > rhs[i])
        return true;
      if (lhs[i] < rhs[i])
        return false;
    }
    return true;
  }
};

ostream &operator<<(ostream &os, const bigint &bi) {
  for (int i = bi.size() - 1; i >= 0; i--)
    os << bi[i];
  return os;
}

bigint gen_bitint(int n) {
  bigint res;

  do {
    bigint k = gen(1, 100);
    int nn = n;
    res = 1;
    while (nn) {
      if (nn & 1)
        res *= k;

      k *= k;
      nn >>= 1;
    }
  } while (res.size() > 100);

  return res;
}

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = gen(1, 10);

  while (t--) {
    int n = gen(1, 200);
    cout << n << endl << gen_bitint(n) << endl;
  }

  return 0;
}
