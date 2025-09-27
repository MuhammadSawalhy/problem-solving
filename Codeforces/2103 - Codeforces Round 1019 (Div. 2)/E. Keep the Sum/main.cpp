#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), A;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    A = a;

    if (is_sorted(all(a))) {
        cout << "0\n";
        return;
    }

    map<int, int> ind;
    int i = -1, j = -1;
    for (int I = 0; I < n; I++) {
        if (ind.count(k - a[I])) {
            i = ind[k - a[I]];
            j = I;
            break;
        }
        ind[a[I]] = I;
    }

    if (i == -1) {
        cout << "-1\n";
        return;
    }

    debug(i, j, a[i], a[j]);

    vector<array<int, 3>> ans;

    auto getA = [&]() {
        auto aa = A;
        for (auto [i, j, d]: ans) {
            assert(aa[i] + aa[j] == k);
            aa[i] -= d, aa[j] += d;
            assert(aa[i] >= 0 && aa[i] <= k);
        }
        return aa;
    };

    auto swapit = [&](int &i, int j, int l) {
        // i will become k
        // debug("swaping", i, j, l);
        // assert(a[i] + a[j] == k);
        // swap make a[i] = a[k]
        int d = a[l] - a[i];
        if (d) {
            a[j] -= d;
            a[i] += d;
            ans.push_back({j, i, d});
        }
        i = l;
        assert(a[i] + a[j] == k);
    };

    if (i != 0) {
        swapit(i, j, 0); // +1
        assert(i == 0);
    }

    if (j != 1) swapit(j, i, 1); // +1
    assert(i == 0 && j == 1);

    debug(a);

    set<pair<int, int>> s;
    for (int i = 2; i < n; i++) {
        s.insert({a[i], i});
    }

    while (s.size()) { // + 2 * (n - 2)
        auto [v, l] = *s.begin();
        s.erase(s.begin());
        swapit(i, j, l);
        if (i != j + 1) {
            s.erase(s.find({a[j + 1], j + 1}));
            int previ = i;
            swapit(i, j, j + 1);
            s.insert({a[previ], previ});
        }
        if (i > j) swap(i, j);
    }

    debug("final", a);
    debug(getA() == a);

    assert(a[n - 2] + a[n - 1] == k);

    {
        int d = k - a[n - 1];
        if (d) {
            a[n - 2] -= d;
            a[n - 1] += d;
            ans.push_back({n - 2, n - 1, d}); // +1
        }
        assert(a[n - 1] == k);
    }

    debug(getA() == a);

    i = n - 2;
    while (i > 0) {
        // swap i and i - 1
        int d = a[i - 1] - a[i];
        if (d) {
            a[n - 1] -= d;
            a[i] += d;
            ans.push_back({n - 1, i, d});
            assert(a[i] == a[i - 1]);
            assert(a[i] + a[n - 1] == k);
        }
        i--;
    }

    int d = a[0];
    if (d) {
        a[0] -= d;
        a[n - 1] += d;
        ans.push_back({0, n - 1, d});
    }

    assert(ans.size() <= 3 * n);
    cout << ans.size() << "\n";
    for (auto [i, j, d]: ans) {
        cout << i + 1 << " " << j + 1 << " " << d << "\n";
    }

    assert(getA() == a);
    assert(is_sorted(all(a)));
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("-----", t);
        solve();
    }

    return 0;
}
