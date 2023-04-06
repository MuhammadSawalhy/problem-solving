// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    ll cnt = 0;
    ll ans = 0;

    map<array<int, 10>, int> fr;
    array<int, 10> x;
    fr[x]++;
    for (int i = 0; i < s.size(); i++) {
        x[s[i] - '0'] ^= 1;
        ans += fr[x];
        fr[x]++;
    }

    cout << ans;

    return 0;
}
