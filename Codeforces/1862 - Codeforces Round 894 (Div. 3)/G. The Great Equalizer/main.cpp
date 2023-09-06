// ﷽
// https://codeforces.com/contest/1862/problem/E
// Codeforces -> Codeforces Round 894 (Div. 3) -> E. Kolya and Movie Theatre

#include <bits/stdc++.h>
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> fr;
    multiset<int> diff, items;
    diff.insert(0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    int diffsum = 0;

    auto remove = [&](int x) {
        auto I = items.lower_bound(x), J = items.upper_bound(x);
        int cnt = fr[x]--;

        if (cnt > 1) {
            items.erase(items.find(x));
            return;
        }

        assert(cnt == 1);

        if (J != items.end()) {
            diff.erase(diff.find(*J - x));
            diffsum -= *J - x;
        }

        if (I != items.begin()) {
            diff.erase(diff.find(x - *prev(I)));
            diffsum -= x - *prev(I);
        }

        if (I != items.begin() && J != items.end()) {
            diff.insert(*J - *prev(I));
            diffsum += *J - *prev(I);
        }

        items.erase(items.find(x));
    };

    auto add = [&](int x) {
        auto I = items.lower_bound(x);
        int cnt = fr[x]++;

        if (cnt > 0) {
            items.insert(x);
            return;
        }

        if (I != items.begin() && I != items.end()) {
            int d = *I - *prev(I);
            diff.erase(diff.find(d));
            diffsum -= d;
        }

        if (I != items.begin()) {
            int d = x - *prev(I);
            diff.insert(d);
            diffsum += d;
        }

        if (I != items.end()) {
            int d = *I - x;
            diff.insert(d);
            diffsum += d;
        }

        items.insert(x);
    };

    for (int i = 0; i < n; i++) {
        add(a[i]);
    }

    while (q--) {
        int i, x;
        cin >> i >> x, i--;
        remove(a[i]);
        add(x);
        a[i] = x;
        cout << *items.begin() + *diff.rbegin() + diffsum << ' ';
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
