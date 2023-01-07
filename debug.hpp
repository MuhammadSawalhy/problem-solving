#pragma once

#include <bits/stdc++.h>

using namespace std;

int indent_level = 0;
string indent_str = "\t";

void indent(ostream &os) {
    int i = indent_level;
    while (i--)
        os << indent_str;
}

template<typename _CharT, typename _Traits>
inline basic_ostream<_CharT, _Traits>&
ENDL(basic_ostream<_CharT, _Traits>& __os)
{
    flush(__os.put(__os.widen('\n')));
    indent(__os);
    return __os;
}

// to make it visible to other print
template<typename T>
ostream &operator<<(ostream &os, const set<T> &x);
template<typename T>
ostream &operator<<(ostream &os, const list<T> &x);
template<typename T>
ostream &operator<<(ostream &os, const valarray<T> &x);
template<typename T>
ostream &operator<<(ostream &os, const multiset<T> &x);
template<typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &x);
template<typename T, typename V>
ostream &operator<<(ostream &os, const map<T, V> &x);
template<typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> &x);
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &x);
template<typename T, size_t SIZE>
ostream &operator<<(ostream &os, const array<T, SIZE> &x);

ostream &operator<<(ostream &os, const __int128 &x) {
    if (x <= 9) return os << (int) x;
    int m = x % 10;
    os << x / 10;
    return os << m;
}

template<typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> &x) {
    return os << '{' << x.first << ", " << x.second << '}';
}

template<typename T, typename V>
ostream &operator<<(ostream &os, const map<T, V> &x) {
    os << '{' << endl;
    indent_level++;
    for (const auto &[key, val]: x) {
        indent(os);
        os << key << ": " << val << ", " << endl;
    }
    indent_level--;
    indent(os);
    return os << '}';
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &x) {
    int f = 0;
    os << '[';
    for (const auto &i: x)
        os << (f++ ? ", " : "") << i;
    return os << ']';
}

template<typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &x) {
    os << '[';
    indent_level++;
    for (const auto &i: x)
        os << ENDL << i << ",";
    indent_level--;
    return os << ENDL << "]";
}

template<typename T>
ostream &operator<<(ostream &os, const set<T> &x) {
    int f = 0;
    os << '{';
    for (const auto &i: x)
        os << (f++ ? ", " : "") << i;
    return os << '}';
}

template<typename T>
ostream &operator<<(ostream &os, const multiset<T> &x) {
    int f = 0;
    os << '{';
    for (const auto &i: x)
        os << (f++ ? ", " : "") << i;
    return os << '}';
}

template<typename T, size_t SIZE>
ostream &operator<<(ostream &os, const array<T, SIZE> &x) {
    vector<T> v(begin(x), end(x));
    return os << v;
}

template<typename T>
ostream &operator<<(ostream &os, const valarray<T> &x) {
    vector<T> v(begin(x), end(x));
    return os << v;
}

template<typename RandomIt>
void debug_itr(RandomIt start, RandomIt end, int split = 0) {
    if (split > 0) {
        cerr << "[";
        indent_level++;
        cerr << ENDL;

        int counter = 0;
        while (start != end) {
            if (counter == split) {
                cerr << ENDL;
                counter = 0;
            }

            cerr << *start;
            start++;
            if (start != end) {
                cerr << ", ";
            }
            
            counter++;
        }
        indent_level--;
        cerr << ENDL;
        cerr << "]" << ENDL;
    } else {
        cerr << '[';
        for (RandomIt it = start; it != end; it++)
            cerr << (it != start ? ", " : "") << *it;
        cerr << ']' << ENDL;
    }
}

template<typename T>
void debug_bits(T val, int splitby = 4, int numofbits = 16) {
    bitset<sizeof(T) * 8> bits(val);
    int start = numofbits - 1;
    for (int i = start; i >= 0; i--)
        cerr << ((start - i) % splitby == 0 && i != start ? " " : "") << bits[i];
    cerr << ENDL;
}

void debug_all() { cerr << ENDL; }
template<typename T, typename... V>
void debug_all(T t, V... v) {
    cerr << t;
    if (sizeof...(v))
        cerr << ", ";
    debug_all(v...);
}

#define debug(x...) (#x[0] != '\0' && (cerr << #x << " = ")), debug_all(x)
