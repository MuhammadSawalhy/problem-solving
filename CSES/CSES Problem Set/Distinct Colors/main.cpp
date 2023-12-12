// ﷽
// https://cses.fi/problemset/task/1139

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

int block_size;
const int N = 2e5 + 5;
int n;
int c[N], fr[N], first[N], last[N];
vector<int> adj[N];
vector<int> value;

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

    MO(vector<int> &arr, vector<Query> &queries) : arr(arr), queries(queries) {}

    int l = 0, r = -1;

    void set_range(Query &q) {
        // [l, r] inclusive
        while (l > q.l) add(arr[--l]);
        while (r < q.r) add(arr[++r]);
        while (l < q.l) remove(arr[l++]);
        while (r > q.r) remove(arr[r--]);
    }

    int cur = 0;

    void add(int x) {
        cur += !fr[x]++;
    }

    void remove(int x) {
        cur -= !--fr[x];
    }

    int getans(Query &q) {
        return cur;
    }

    vector<int> ans() {
        block_size = arr.size() / sqrt(queries.size()) + 1;
        vector<int> ans(queries.size());
        sort(all(queries));

        l = queries.front().l, r = queries.front().l - 1;
        for (auto &q: queries) {
            set_range(q);
            ans[q.idx] = getans(q);
        }

        return ans;
    }
};

void dfs(int i, int p) {
    first[i] = value.size();
    value.push_back(c[i]);
    for (auto j: adj[i]) {
        if (j == p) continue;
        dfs(j, i);
    }
    last[i] = value.size() - 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i], a[i] = c[i];
    }

    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        c[i] = lower_bound(a, a + n, c[i]) - a;
    }

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 0);

    vector<MO::Query> queries;
    for (int i = 0; i < n; i++) {
        queries.push_back(MO::Query(first[i], last[i], i));
    }

    auto ans = MO(value, queries).ans();

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}
