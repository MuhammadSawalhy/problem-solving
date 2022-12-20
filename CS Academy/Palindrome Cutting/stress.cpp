#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

int n, m;
long long ans;

bool check(vector<int> &arr, int start, int end) {
  int size = end - start;
  if (size & 1)
    return false;
  bool valid = true;
  for (int i = 0; i < size / 2; i++) {
    if (arr[start + i] != arr[start + (size - 1 - i)]) {
      valid = false;
      break;
    }
  }
  if (valid)
    return true;

  for (int i = start + 1; i < end; i++) {
    if ((i - start) % 2 == 0 && (end - i) % 2 == 0) {
      if (check(arr, start, i) && check(arr, i, end))
        return true;
    }
  }

  return false;
}

void brute(int i, vector<int> &arr) {
  if (i == n) {
    if (check(arr, 0, arr.size())) ans++;
    return;
  }

  for (int j = 1; j <= m; j++) {
    arr.push_back(j);
    brute(i + 1, arr);
    arr.pop_back();
  }
}

int main() {
  cin >> n >> m;
  ans = 0;
  vector<int> arr;
  brute(0, arr);
  cout << ans << endl;
}
