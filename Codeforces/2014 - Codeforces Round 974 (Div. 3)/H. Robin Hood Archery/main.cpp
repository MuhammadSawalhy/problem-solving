// ﷽
// https://codeforces.com/contest/2014/problem/H

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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

int block_size;
struct MO {
    struct Query {
        int l, r, idx;
        bool operator<(const Query &q) const {
            if (l / block_size != q.l / block_size)
                return pair(l, r) < pair(q.l, q.r);
            return (l / block_size & 1) ? (r < q.r) : (r > q.r);
        }
    };

    vector<int> arr, freq;
    vector<Query> queries;
    int l = 0, r = -1;

    MO() {}
    MO(const vector<int> &arr) : arr(arr) {
        freq = vector<int>(arr.size());
    }

    void add_query(const Query &q) {
        queries.push_back(q);
    }

    vector<int> get_ans() {
        block_size = arr.size() / sqrt(queries.size()) + 1;
        vector<int> ans(queries.size());
        sort(all(queries));

        l = queries.front().l, r = queries.front().l - 1;
        for (auto &q: queries) {
            set_range(q);
            ans[q.idx] = ans_query(q);
        }

        return ans;
    }

    void set_range(Query &q) {
        // [l, r] inclusive
        while (l > q.l) add(arr[--l]);
        while (r < q.r) add(arr[++r]);
        while (l < q.l) remove(arr[l++]);
        while (r > q.r) remove(arr[r--]);
    }

    int cnt = 0;
    void add(int x) {
        freq[x]++;
        if (freq[x] & 1) cnt++;
        else cnt--;
    }

    void remove(int x) {
        freq[x]--;
        if (freq[x] & 1) cnt++;
        else cnt--;
    }

    int ans_query(Query &q) {
        return cnt == 0;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    b = a;
    sort(all(b));

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(b), a[i]) - b.begin();
    }

    auto m = MO(a);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        m.add_query({l, r, i});
    }

    auto ans = m.get_ans();

    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
