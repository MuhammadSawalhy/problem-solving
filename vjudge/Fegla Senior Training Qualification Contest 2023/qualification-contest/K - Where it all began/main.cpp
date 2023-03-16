// ﷽
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

    int n;
    cin >> n;

    if (n & 1) {
        cout <<  -1 << endl;
        return 0;
    }

    int odds = 0, evens = 0;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        odds += a & 1;
        evens += a & 1 ^ 1;
    }

    cout << abs(odds - evens) / 2 << endl;

    return 0;
}
