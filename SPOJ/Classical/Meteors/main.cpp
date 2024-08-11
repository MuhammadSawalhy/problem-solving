// ﷽
// https://www.spoj.com/problems/METEORS/

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
#define pii pair<int, int>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 512 * 1024;
int tr[N * 2], owner[N], val[N], ans[N], l[N], r[N], a[N], n, m;
vector<int> slots[N];


void tree_add(int low, int high, int v) {
    assert(low <= high);
    low += N;
    high += N;
    tr[low] += v;
    if (low != high) tr[high] += v;
    while (low + 1 < high) {
        if (low % 2 == 0) tr[low + 1] += v;
        if (high % 2 == 1) tr[high - 1] += v;
        low /= 2;
        high /= 2;
    }
}

long long tree_get(int where) {
    long long s = 0;
    for (int x = N + where; x >= 1; x /= 2)
        s += tr[x];
    return s;
}

int get_sum(int i) {
    int sum = 0;
    for (auto j: slots[i])
        sum += tree_get(j);
    return sum;
}

void update(int l, int r, int a) {
    if (l <= r)
        tree_add(l, r, a);
    else {
        tree_add(l, m - 1, a);
        tree_add(0, r, a);
    }
}

int j = 0;

void set_queries(int i) {
    debug(i);
    while (j <= i) {
        debug('+', j, l[j], r[j]);
        update(l[j], r[j], a[j]);
        j++;
    }

    while (j > i + 1) {
        j--;
        debug('-', j, l[j], r[j]);
        update(l[j], r[j], -a[j]);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> owner[i], owner[i]--, slots[owner[i]].push_back(i);
    for (int i = 0; i < n; i++) cin >> val[i];

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> l[i] >> r[i] >> a[i], l[i]--, r[i]--;
    }

    typedef tuple<int, int, vector<int>> T;
    vector<T> qu(k * 30);
    vector<int> x(n);
    iota(all(x), 0);

    qu[0] = T(0, k - 1, x);

    for(int j = 0, size = 1; j < size; j++) {
        auto &[l, r, v] = qu[j];

        int mid = (l + r) / 2;
        debug(l, r, mid, v);

        set_queries(mid);

        if (l == r) {
            for (auto i: v) {
                int sum = get_sum(i);
                if (sum >= val[i]) ans[i] = mid;
                else ans[i] = -1;
            }
            vector<int>().swap(v);
            continue;
        }

        vector<int> litems, ritems;

        for (auto i: v) {
            int sum = get_sum(i);
            debug(i, sum);
            if (sum >= val[i]) litems.push_back(i);
            else ritems.push_back(i);
        }

        vector<int>().swap(v);
        if (sz(litems)) qu[size++] = T(l, mid, litems);
        if (sz(ritems)) qu[size++] = T(mid + 1, r, ritems);
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) cout << "NIE\n";
        else cout << ans[i] + 1 << '\n';
    }

    // (n + k log m + m log m) * log k
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
