// Date: 03-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

void binary_search() {
  string l;

  int mod = 34943;

  while (true) {
    getline(cin, l);
    if (l == "#")
      break;

    debug(l);
    int n = 1 << 16;
    int crc = 0;
    for (int j = (int)l.size() - 1; j >= 0; j--) {
      int ch = l[j];
      for (int i = 0; i < 8; i++) {
        if ((ch >> i) & 1) {
          crc += n;
          crc %= mod;
        }

        n *= 2;
        n %= mod;
      }
    }

    crc = (mod - crc) % mod;
    printf("%02X %02X\n", crc >> 8, crc & 0x00FF);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  // cin >> t_cases;
  while (t_cases--) {
    binary_search();
  }
  return 0;
}
