#pragma once

#include <iostream>
#include <iterator>
#include <type_traits>
using namespace std;

int indent_level = 0, SPLIT = 0;
string indent_str = "\t";
bool general_debugging;

void indent(ostream &os) {
    int i = indent_level;
    while (i--)
        os << indent_str;
}

template<typename _CharT, typename _Traits>
inline basic_ostream<_CharT, _Traits> &
ENDL(basic_ostream<_CharT, _Traits> &__os) {
    flush(__os.put(__os.widen('\n')));
    indent(__os);
    return __os;
}

template<typename T>
void debug_one(T t);

namespace debug_details
{

// To allow ADL with custom begin/end
using std::begin;
using std::end;

template<typename T>
auto is_iterable_impl(int) -> decltype(begin(std::declval<T &>()) !=
                                               end(std::declval<T &>()),                         // begin/end and operator !=
                                       void(),                                                   // Handle evil operator ,
                                       ++std::declval<decltype(begin(std::declval<T &>())) &>(), // operator ++
                                       void(*begin(std::declval<T &>())),                        // operator*
                                       std::true_type{});

template<typename T>
std::false_type is_iterable_impl(...);

} // namespace debug_details

template<typename T>
using is_iterable = decltype(debug_details::is_iterable_impl<T>(0));

template<typename RandomIt>
void debug_itr(RandomIt start, RandomIt end, int split = SPLIT) {
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

            debug_one(*start);
            start++;
            if (start != end) {
                cerr << ", ";
            }

            counter++;
        }
        indent_level--;
        cerr << ENDL;
        cerr << "]";
    } else {
        cerr << '[';
        for (RandomIt it = start; it != end; it++)
            cerr << (it != start ? ", " : ""), debug_one(*it);
        cerr << ']';
    }
    if (!general_debugging)
        cerr << ENDL;
}

template<typename Iterable,
         enable_if_t<is_iterable<Iterable>::value, bool> = true>
void debug_itr(Iterable it, int len, int split = 0) {
    debug_itr(begin(it), begin(it) + len, split);
}

template<typename T>
void debug_itr(const T items[], int len, int split = 0) {
    debug_itr(items, items + len, split);
}

template<typename T, size_t s>
void debug_itr(const T items[][s], int len, int split = s) {
    if (split != s) {
        T newitems[len][split];
        for (int i = 0; i < len; i++)
            for (int j = 0; j < split; j++)
                newitems[i][j] = items[i][j];
        return debug_itr(&newitems[0][0], &newitems[0][0] + len * split, split);
    }
    debug_itr(&items[0][0], &items[0][0] + len * split, split);
}

template<typename T>
void debug_bits(const T val, int splitby = 4, int numofbits = 16) {
    __int128 bits = (val);
    int start = numofbits - 1;
    for (int i = start; i >= 0; i--)
        cerr << ((start - i) % splitby == 0 && i != start ? " " : "")
             << (int) (bits >> i & 1);
    cerr << ENDL;
}

#ifdef _STL_PAIR_H
template<typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> &x) {
    os << '{';
    debug_one(x.first);
    os << ", ";
    debug_one(x.second);
    os << '}';
    return os;
}
#endif

#ifdef _STL_QUEUE_H
template<typename T>
ostream &operator<<(ostream &os, const queue<T> &x) {
    auto copy = x;
    vector<T> v;
    while (copy.size())
        v.push_back(copy.front()), copy.pop();
    bool gd = general_debugging;
    general_debugging = true;
    debug_one(v);
    general_debugging = gd;
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const priority_queue<T> &x) {
    auto copy = x;
    vector<T> v;
    while (copy.size())
        v.push_back(copy.top()), copy.pop();
    debug_one(v);
    return os;
}
#endif

#ifdef _GLIBCXX_TUPLE
// helper function to print a tuple of any size
template<class Tuple, std::size_t N>
struct TuplePrinter {
    static void print(ostream &os, const Tuple &t) {
        TuplePrinter<Tuple, N - 1>::print(os, t);
        os << ", " << get<N - 1>(t);
    }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
    static void print(ostream &os, const Tuple &t) { os << get<0>(t); }
};

template<class... Args>
ostream &operator<<(ostream &os, const tuple<Args...> &t) {
    os << "(";
    TuplePrinter<decltype(t), sizeof...(Args)>::print(os, t);
    return os << ")";
}
#endif

template<typename T,
         enable_if_t<is_iterable<T>::value, bool> = true>
void debug_one_helper(T t) {
    bool gd = general_debugging;
    general_debugging = true;
    debug_itr(begin(t), end(t));
    general_debugging = gd;
}

template<typename T,
         enable_if_t<!is_iterable<T>::value, bool> = true>
void debug_one_helper(T t) {
    cerr << t;
}

void debug_one_helper(string t) {
    cerr << '"' << t << '"';
}

template<typename T>
void debug_one(T t) {
    debug_one_helper(t);
}

void debug_all() {
    cerr << ENDL;
}

// vector, set, map, multimap, multiset, array
template<typename T, typename... V>
void debug_all(T t, V... v) {
    debug_one(t);
    if (sizeof...(v))
        cerr << ", ";
    debug_all(v...);
}

#define debug(x...) (#x[0] != '\0' && (cerr << #x << " = ")), debug_all(x)
