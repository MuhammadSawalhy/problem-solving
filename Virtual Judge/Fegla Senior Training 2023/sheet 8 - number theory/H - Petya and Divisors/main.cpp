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

const int N = 1e5 + 5;
vector<int> divs[N];
int block_size, x[N];
int n;


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

    vector<Query> queries;

    MO(vector<Query> &queries) : queries(queries) {}

    int l = 0, r = -1;
    vector<int> fr = vector<int>(N);

    void set_range(Query &q) {
        // [l, r] inclusive
        while (l > q.l) add(x[--l]);
        while (r < q.r) add(x[++r]);
        while (l < q.l) remove(x[l++]);
        while (r > q.r) remove(x[r--]);
    }

    void add(int x) {
        for (auto d: divs[x]) {
            fr[d]++;
        }
    }

    void remove(int x) {
        for (auto d: divs[x]) {
            fr[d]--;
        }
    }

    int getans(Query &q) {
        int ans = 0;
        for (auto div: divs[x[q.idx]]) {
            ans += fr[div] == 0;
        }
        return ans;
    }

    vector<int> ans() {
        block_size = sqrt(n) + 1;
        vector<int> ans(N, -1);
        sort(all(queries));

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

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
    }

    cin >> n;

    vector<int> myans(n, -1);
    vector<MO::Query> queries;

    vector<int> arr;

    for (int i = 0, y; i < n; i++) {
        cin >> x[i] >> y;
        if (y == 0) {
            myans[i] = divs[x[i]].size();
            continue;
        }
        queries.emplace_back(i - y, i - 1, i);
        debug(i - y, i - 1, i);
    }

    if (queries.size()) {
        auto ans = MO(queries).ans();

        for (int i = 0; i < n; i++) {
            if (ans[i] != -1)
                assert(myans[i] == -1), myans[i] = ans[i];
        }
    }

    for (int i = 0; i < n; i++)
        cout << myans[i] << '\n',
                assert(myans[i] != -1);
    ;

    return 0;
}
