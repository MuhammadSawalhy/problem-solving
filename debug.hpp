#pragma once

#include <bits/stdc++.h>

using namespace std;

constexpr string_view ITR = "ITR>>>>";
constexpr string_view BITS = "BITS>>>>";

int indent_level = 1;
string indent_str = "\t";

void indent() {
  int i = indent_level;
  while (i--) {
    cerr << indent_str;
  }
}

void print(char x) { cerr << '\'' << x << '\''; }
void print(bool x) { cerr << (x ? "true" : "false"); }
void print(const char *x) { cerr << '\"' << x << '\"'; }
void print(const std::string &x) { cerr << '\"' << x << '\"'; }

// to make it visible to other print
template <typename T> void print(const set<T> &x);
template <typename T> void print(const list<T> &x);
template <typename T> void print(const vector<T> &x);
template <typename T> void print(const array<T, 2> &x);
template <typename T> void print(const array<T, 3> &x);
template <typename T> void print(const array<T, 4> &x);
template <typename T> void print(const valarray<T> &x);
template <typename T> void print(const vector<vector<T>> &x);
template <typename T, typename V> void print(const map<T, V> &x);
template <typename T, typename V> void print(const pair<T, V> &x);

template <typename T> void print(const T &x) { cerr << x; }

template <typename T, typename V> void print(const pair<T, V> &x) {
  cerr << '{';
  print(x.first);
  cerr << ", ";
  print(x.second);
  cerr << '}';
}

template <typename T, typename V> void print(const map<T, V> &x) {
  cerr << '{' << endl;
  indent_level++;
  for (const auto &[key, val] : x) {
    indent();
    print(key);
    cerr << ": ";
    print(val);
    cerr << "," << endl;
  }
  indent_level--;
  indent();
  cerr << '}';
}

template <typename T> void print(const vector<T> &x) {
  int f = 0;
  cerr << '[';
  for (const auto &i : x)
    cerr << (f++ ? ", " : ""), print(i);
  cerr << ']';
}

template <typename T> void print(const vector<vector<T>> &x) {
  cerr << '[';
  indent_level++;
  for (const auto &i : x) {
    cerr << endl;
    indent();
    print(i);
    cerr << ",";
  }
  cerr << endl;
  indent_level--;
  indent();
  cerr << ']';
}

template <typename T> void print(const set<T> &x) {
  int f = 0;
  cerr << '{';
  for (const auto &i : x)
    cerr << (f++ ? ", " : ""), print(i);
  cerr << '}';
}

template <typename T> void print(const list<T> &x) {
  vector<T> v(begin(x), end(x));
  print(v);
}

template <typename T> void print(const array<T, 2> &x) {
  vector<T> v(begin(x), end(x));
  print(v);
}

template <typename T> void print(const array<T, 3> &x) {
  vector<T> v(begin(x), end(x));
  print(v);
}

template <typename T> void print(const array<T, 4> &x) {
  vector<T> v(begin(x), end(x));
  print(v);
}

template <typename T> void print(const valarray<T> &x) {
  vector<T> v(begin(x), end(x));
  print(v);
}

template <typename RandomIt> void debug_itr(RandomIt start, RandomIt end) {
  cerr << '[';
  for (RandomIt it = start; it != end; it++)
    cerr << (it != start ? ", " : ""), print(*it);
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

void debug_all() { cerr << endl; }
template <typename T, typename... V> void debug_all(T t, V... v) {
  print(t);
  if (sizeof...(v))
    cerr << ", ";
  debug_all(v...);
}

template <typename... V> void debug_port(V... v) { debug_all(v...); }

template <typename T>
void debug_port(const string_view t, T val, int splitby = 4,
                int numofbits = 16) {
  debug_bits(val, splitby, numofbits);
  return;
}

template <typename RandomIt>
void debug_port(const string_view t, RandomIt start, RandomIt end) {
  debug_itr(start, end);
  return;
}

#define debug(x...) cerr << #x << " = ", debug_port(x)
