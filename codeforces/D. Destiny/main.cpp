// ﷽
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

struct Query {
    int l, r;
    int k;
    bool operator<(const Query &q) {
        return r < q.r;
    }
};

struct MO {
    vector<int> arr;
    vector<Query> queries;

    MO(vector<int> &arr, vector<Query> &queries) : arr(arr), queries(queries) {}

    int l = 0, r = -1;
    map<int, int> fr;
    set<pair<int, int>> s;

    void set_range(Query &q) {
        // [l, r] inclusive
        while (r > q.r) remove(arr[r--]);
        while (r < q.r) add(arr[++r]);
        while (l < q.l) remove(arr[l++]);
        while (l > q.l) add(arr[--l]);
    }

    void add(int x) {
        if (s.count({x, fr[x]})) {
            s.erase({x, fr[x]});
        }
        fr[x]++;
        s.insert({x, fr[x]});
    }

    void remove(int x) {
        s.erase({x, fr[x]});
        fr[x]--;
        s.insert({x, fr[x]});
    }

    int getans(Query q) {
        auto [r, l, k] = q;
        auto it = s.lower_bound({(r - l + 1 + k) / k, 0});

        if (it == s.end())
            return -1;

        return it->second;
    }

    vector<int> ans() {
        int q = queries.size();
        vector<int> ans(q);
        vector<int> order(q);
        iota(all(order), 0);
        sort(all(order), [&](auto l, auto r) { return queries[l] < queries[r]; });

        int SQ = sqrtl(q);
        vector<vector<int>> buckets(q);

        for (auto i: order) {
            buckets[queries[i].l / SQ].push_back(i);
        }

        for (int i = 0; i < q; i++) {
            // we have sorted bucket i according to end edge
            for (auto j: buckets[i]) {
                set_range(queries[j]);
                ans[j] = getans(queries[j]);
            }
        }

        return ans;
    }
};


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;

    cin >> n;
    vector<int> arr(n);
    vector<Query> qu;
    for (auto &i: arr) cin >> i;
    for (int i = 0, l, r, k; i < q; i++) {
        cin >> l >> r >> k, l--, r--;
        qu.emplace_back(l, r, k);
    }

    auto ans = MO(arr, qu).ans();

    for (auto i: ans)
        cout << i << '\n';

    return 0;
}
