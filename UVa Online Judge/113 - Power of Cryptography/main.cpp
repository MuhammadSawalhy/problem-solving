// Date: 06-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

int n;
string p;

class big_int {
public:
  vector<int> digits;

  big_int(unsigned long long value = 0) { set_value(value); }

  big_int(string s) {
    digits.resize(s.size());
    for (int i = (int)s.size() - 1; i >= 0; i--) {
      digits[i] = s[(int)s.size() - 1 - i] - '0';
    }
  }

  template <typename RandomIt> big_int(RandomIt begin, RandomIt end) {
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

  big_int &operator*=(const big_int &rhs) {
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

  big_int &operator+=(const big_int &rhs) {
    digits.resize(max(size(), rhs.size()) + 1);
    for (int i = 0; i < rhs.size(); i++) {
      digits[i] += rhs[i];
      digits[i + 1] += digits[i] / 10;
      digits[i] %= 10;
    }
    trim();
    return *this;
  }

  friend big_int operator+(const big_int &lhs, const big_int &rhs) {
    big_int res = lhs;
    res.digits.resize(max(rhs.size(), lhs.size()) + 1);
    for (int i = 0; i < (int)res.size() - 1; i++) {
      res[i] += rhs[i];
      res[i + 1] += res[i] / 10;
      res[i] %= 10;
    }
    res.trim();
    return res;
  }

  friend big_int operator*(const big_int &lhs, const big_int &rhs) {
    big_int res;
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

  friend bool operator==(const big_int &lhs, const big_int &rhs) {
    return lhs.digits == rhs.digits;
  }

  friend bool operator>(const big_int &lhs, const big_int &rhs) {
    if (lhs.size() != rhs.size())
      return lhs.size() > rhs.size();
    for (int i = lhs.size() - 1; i >= 0; i--) {
      if (lhs[i] > rhs[i])
        return true;
    }
    return false;
  }

  friend bool operator>=(const big_int &lhs, const big_int &rhs) {
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

ostream &operator<<(ostream &os, const big_int &bi) {
  for (int i = bi.size() - 1; i >= 0; i--)
    os << bi[i];
  return os;
}

void solve() {
  big_int bi = p;

  auto valid = [&](big_int k) {
    int nn = n;
    big_int res = 1;
    while (nn) {
      if (nn & 1) {
        res *= k;
      }

      k *= k;
      nn >>= 1;
    }

    return res >= p;
  };

  int s = 0, e = INT_MAX;
  while (e - s > 1) {
    int mid = (s + e) >> 1;
    if (valid(mid)) {
      e = mid;
    } else {
      s = mid;
    }
  }

  cout << e << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  while (cin >> n >> p) {
    solve();
  }

  return 0;
}
