#pragma once

#include <bits/stdc++.h>

using namespace std;

int indent = 1;
string indent_str = "\t";

void __indent() {
  int i = indent;
  while (i--) {
    cerr << indent_str;
  }
}

void __print(char x) { cerr << '\'' << x << '\''; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const std::string &x) { cerr << '\"' << x << '\"'; }

// to make it visible to other __print
template <typename T> void __print(const set<T> &x);
template <typename T> void __print(const list<T> &x);
template <typename T> void __print(const vector<T> &x);
template <typename T> void __print(const array<T, 2> &x);
template <typename T> void __print(const array<T, 3> &x);
template <typename T> void __print(const valarray<T> &x);
template <typename T> void __print(const vector<vector<T>> &x);
template <typename T, typename V> void __print(const map<T, V> &x);
template <typename T, typename V> void __print(const pair<T, V> &x);

template <typename T> void __print(const T &x) { cerr << x; }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}

template <typename T, typename V> void __print(const map<T, V> &x) {
  cerr << '{' << endl;
  indent++;
  for (const auto &[key, val] : x) {
    __indent();
    __print(key);
    cerr << ": ";
    __print(val);
    cerr << "," << endl;
  }
  indent--;
  __indent();
  cerr << '}';
}

template <typename T> void __print(const vector<T> &x) {
  int f = 0;
  cerr << '[';
  for (const auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << ']';
}

template <typename T> void __print(const vector<vector<T>> &x) {
  cerr << '[';
  indent++;
  for (const auto &i : x) {
    cerr << endl;
    __indent();
    __print(i);
    cerr << ",";
  }
  cerr << endl;
  indent--;
  __indent();
  cerr << ']';
}

template <typename T> void __print(const set<T> &x) {
  int f = 0;
  cerr << '{';
  for (const auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << '}';
}

template <typename T> void __print(const list<T> &x) {
  vector<T> v(begin(x), end(x));
  __print(v);
}

template <typename T> void __print(const array<T, 2> &x) {
  vector<T> v(begin(x), end(x));
  __print(v);
}

template <typename T> void __print(const array<T, 3> &x) {
  vector<T> v(begin(x), end(x));
  __print(v);
}

template <typename T> void __print(const valarray<T> &x) {
  vector<T> v(begin(x), end(x));
  __print(v);
}

void _print() { cerr << endl; }

template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

template <typename RandomIt> void debug_itr(RandomIt start, RandomIt end) {
  cerr << '[';
  for (RandomIt it = start; it != end; it++)
    cerr << (it != start ? ", " : ""), __print(*it);
  cerr << ']' << endl;
}

template <typename T>
void debug_bits(T val, int splitby = 4, int numofbits = 16) {
  bitset<sizeof(T) * 8> bits(val);
  int start = numofbits - 1;
  for (int i = start; i >= 0; i--)
    cerr << ((start - i) % splitby == 0 && i != start ? " " : "") << bits[i];
  cerr << endl;
}

#define debug(x...)                                                            \
  cerr << #x << " = ";                                                         \
  _print(x)
