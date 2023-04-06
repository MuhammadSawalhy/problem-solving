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

int block_size;

struct MO {
    struct Query {
        int l, r, idx;
        Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
        bool operator<(const Query &q) const {
            if (l / block_size != q.l / block_size)
                return pair(l, r) < pair(q.l, q.r);
            return (l / block_size & 1) ? (r < q.r) : (r > q.r);
        }
    };

    vector<int> arr;
    vector<Query> queries;
    vector<int> triples = vector<int>((int)2e5 + 5);
    vector<int> fr = vector<int>((int)2e5 + 5);

    MO(vector<int> &arr, vector<Query> &queries) : arr(arr), queries(queries) {}

    int l = 0, r = -1;

    void set_range(Query &q) {
        // [l, r] inclusive
        while (l > q.l) add(arr[--l]);
        while (r < q.r) add(arr[++r]);
        while (l < q.l) remove(arr[l++]);
        while (r > q.r) remove(arr[r--]);
    }

    map<int, int> one, dble;
    ll ANS = 0;

    void add(int x) {
        ANS -= triples[fr[x]];
        ANS += triples[++fr[x]];
    }

    void remove(int x) {
        ANS -= triples[fr[x]];
        ANS += triples[--fr[x]];
    }

    int getans(Query &q) {
        return ANS;
    }

    vector<int> ans() {
        block_size = arr.size() / sqrt(queries.size()) + 1;
        vector<int> ans(queries.size());
        sort(all(queries));

        for (int i = 0; i < 2e5 + 5; i++)
            triples[i] = i * (i - 1) * (i - 2) / 6;

        l = queries.front().l, r = queries.front().l - 1;
        for (auto &q: queries) {
            set_range(q);
            ans[q.idx] = getans(q);
        }

        return ans;
    }
};


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;

    cin >> n >> q;
    vector<int> arr(n);
    for (auto &i: arr) cin >> i;

    vector<MO::Query> qu;
    for (int i = 0, l, r; i < q; i++) {
        cin >> l >> r, l--, r--;
        qu.emplace_back(l, r, i);
    }

    auto ans = MO(arr, qu).ans();

    for (auto i: ans)
        cout << i << '\n';

    return 0;
}
