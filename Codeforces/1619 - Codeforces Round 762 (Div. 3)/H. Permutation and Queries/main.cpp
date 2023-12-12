// ﷽
// https://codeforces.com/contest/1619/problem/H

#include <bits/stdc++.h>
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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

const int N = 1e5 + 5;
const int Q = sqrt(N);
int a[N], r[N], b[N];
int n, q;

void update_one(int x) {
    int y = x;
    for (int i = 0; i < Q; i++) {
        y = a[y];
    }
    b[x] = y;
}

void update(int x) {
    update_one(x);
    for (int i = 0; i < Q; i++) {
        int y = r[x];
        b[y] = r[b[x]];
        x = y;
    }
}

int query(int x, int k) {
    while (k >= Q) x = b[x], k -= Q;
    while (k--) x = a[x];
    return x;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
        r[a[i]] = i;
    }


    for (int i = 0; i < n; i++) {
        update_one(i);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            swap(r[a[x]], r[a[y]]);
            swap(a[x], a[y]);
            update(a[x]);
            update(a[y]);
        } else {
            int x, k;
            cin >> x >> k;
            x--;
            cout << query(x, k) + 1 << endl;
        }
    }

    return 0;
}
