// ﷽
// https://codeforces.com/contest/1956/problem/D

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;


vector<int> a(18);
vector<pair<int, int>> ops;

void incops(int l, int r, int base) {
    // from l to r, there should be no zero
    if (l == r) {
        ops.push_back({l, r}); // will be zero
        return;
    }
    incops(l, r - 1, base);
    // a[r] == 1
    if (r == l + 1 && base == 1) {
        return;
    }
    ops.push_back({l, r}); // all non-zero
    incops(l, r - 1, r - l + 1);
}

void addops(int l, int r) {
    bool zero = false;
    for (int i = l; i <= r; i++) {
        if (a[i] == 0) zero = true;
    }

    if (zero) {
        ops.push_back({l, r});
        ops.push_back({l, r});
        ops.push_back({l, r});
    } else {
        ops.push_back({l, r});
        ops.push_back({l, r});
    }

    // now all are zeros
    incops(l, r, 1);
    ops.push_back({l, r});
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = -1, mask;

    for (int curmask = 0; curmask < 1 << n; curmask++) {
        bitset<19> b = curmask;
        int cursum = 0;
        for (int j = 0; j < n;) {
            if (b[j] == 0) {
                cursum += a[j];
                j++;
                continue;
            }
            int k = j;
            while (k < n && b[k] == 1) k++;

            // from j to k - 1 are bit with value 1
            cursum += (k - j) * (k - j);
            j = k;
        }

        if (cursum > sum) {
            sum = cursum;
            mask = curmask;
        }
    }

    bitset<19> b = mask;
    for (int j = 0; j < n;) {
        if (b[j] == 0) {
            j++;
            continue;
        }
        int k = j;
        while (k < n && b[k] == 1) k++;

        // from j to k - 1 are bit with value 1
        addops(j, k - 1);
        j = k;
    }

    assert(sz(ops) <= 5e5);
    cout << sum << ' ' << sz(ops) << endl;
    for (auto [l, r]: ops) {
        cout << l + 1 << ' ' << r + 1 << endl;
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
