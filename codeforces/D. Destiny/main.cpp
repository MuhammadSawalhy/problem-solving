// ﷽
#include <bits/stdc++.h>
#include <climits>
#include <random>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define all(v) v.begin(), v.end()

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

struct Query {
    int l, r, k, i;
};

struct MO {
    vector<int32_t> arr;
    vector<Query> queries;

    int l = 0, r = -1;
    vector<int32_t> fr;

    MO(vector<int32_t> arr, vector<Query> queries) : arr(arr), queries(queries), fr(arr.size() + 1) {}

    void set_range(Query &q) {
        // [l, r] inclusive
        while (r > q.r) remove(arr[r--]);
        while (r < q.r) add(arr[++r]);
        while (l < q.l) remove(arr[l++]);
        while (l > q.l) add(arr[--l]);
    }

    void add(int x) {
        fr[x]++;
    }

    void remove(int x) {
        fr[x]--;
    }

    int getans(Query &q) {
        int ans = 1e9;
        int iter = 100;
        int target = (q.r - q.l + 1 + q.k) / q.k;

        while (iter--) {
            int i = rand_int(q.l, q.r);
            if (fr[arr[i]] >= target) {
                ans = min(ans, arr[i]);
            }
        }

        return ans == 1e9 ? -1 : ans;
    }

    vector<int> ans() {
        int q = queries.size();
        int SQ = sqrtl(arr.size()) + 1;
        vector<int> ans(q);

        sort(all(queries), [&](Query l, Query r) {
            if (l.l / SQ == r.l / SQ) {
                return l.l / SQ % 2 == 1 ? l.r > r.r : l.r < r.r;
            } else {
                return l.l < r.l;
            }
        });

        for (int i = 0; i < q; i++) {
            set_range(queries[i]);
            ans[queries[i].i] = getans(queries[i]);
        }

        return ans;
    }
};


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;

    cin >> n >> q;
    vector<int32_t> arr(n);
    vector<Query> qu;
    for (auto &i: arr) cin >> i;

    for (int i = 0, l, r, k; i < q; i++) {
        cin >> l >> r >> k, l--, r--;
        Query query;
        query.l = l;
        query.r = r;
        query.k = k;
        query.i = i;
        qu.push_back(query);
    }

    auto ans = MO(arr, qu).ans();

    for (auto i: ans)
        cout << i << '\n';

    return 0;
}
