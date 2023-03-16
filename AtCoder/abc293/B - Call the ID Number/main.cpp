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

    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> s;

    for (int i = 0; i < n; i++) {
        if (!s.count(i + 1)) {
            s.insert(a[i]);
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!s.count(i + 1))
            ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for (auto i: ans)
        cout << i << " ";

    return 0;
}
