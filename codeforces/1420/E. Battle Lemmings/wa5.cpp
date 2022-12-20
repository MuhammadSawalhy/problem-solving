// ----------------------------------------------------------------------------
// Problem : E. Battle Lemmings
// Author  : Muahmmad Assawalhy
// Date    : 12-09-22
// ----------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

typedef __int128 BigInt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  BigInt a = 0;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    a |= (BigInt) b << i;
  }

  int zeros = 0;
  int z = 0;
  int val = 0;
  for (int i = 0; i < n; i++) {
    if ((a >> i & 1) == 0) {
      val += zeros;
      z++;
    } else {
      zeros += z;
      z = 0;
    }
  }

  const int SIZE = n * (n - 1) / 2 + 1;
  vector<int> allvals(SIZE);
  vector<vector<BigInt>> ways(SIZE);
  map<BigInt, bool> vis;
  allvals[0] = val;
  ways[0] = {a};

  for (int i = 0; i < SIZE - 1; i++) {
    allvals[i + 1] = allvals[i];
    for (auto t: ways[i]) {
      if (vis[t]) continue;
      vis[t] = true;
      int lz = 0, rz = 0;
      int l = 0, r = 0;

      while (l < n && (t >> l & 1) != 1) {
        l++;
        lz++;
      }

      while (l < n) {
        rz = 0;
        r = l + 1;
        while (r < n && (t >> r & 1) != 1) {
          r++;
          rz++;
        }

        // move to the left
        if (lz) {
          int myval = allvals[i];
          BigInt myt = t;
          myt ^= (BigInt) 3 << (l - 1);
          myval -= lz * rz;
          myval += (lz - 1) * (rz + 1);
          if (myval > allvals[i + 1]) {
            allvals[i + 1] = myval;
            ways[i + 1].clear();
            ways[i + 1].push_back(myt);
          } else if (myval == allvals[i + 1]) {
            if (!vis[myt])
              ways[i + 1].push_back(myt);
          }
        }

        // move to the right
        if (rz) {
          int myval = allvals[i];
          BigInt myt = t;
          myt ^= (BigInt) 3 << (l);
          myval -= lz * rz;
          myval += (lz + 1) * (rz - 1);
          if (myval > allvals[i + 1]) {
            allvals[i + 1] = myval;
            ways[i + 1].clear();
            ways[i + 1].push_back(myt);
          } else if (myval == allvals[i + 1]) {
            if (!vis[myt])
              ways[i + 1].push_back(myt);
          }
        }

        l = r;
        lz = rz;
      }
    }
  }

  for (int i = 0; i < SIZE; i++)
    cout << allvals[i] << " ";
  cout << endl;

  return 0;
}
