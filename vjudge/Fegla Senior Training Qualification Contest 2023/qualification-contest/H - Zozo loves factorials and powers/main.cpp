// ﷽
#include <cmath>
#include <map>
#include <array>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    long double a = (long double) x * log(n), b = 0;

    for (int i = 1; i <= x; i++)
        b += log(i);

    if (a > b) {
        cout << "zozo" << endl;
    } else {
        cout << "zezo" << endl;
    }
    

    return 0;
}
