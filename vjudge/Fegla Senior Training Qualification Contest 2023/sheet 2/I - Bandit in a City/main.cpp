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

const int N = 2e5;
vector<int> adj[N];
int a[N];

struct Result {
    ll count, sum, max;
};

Result dfs(int i) {
    if (adj[i].empty()) {
        return { 1, a[i], a[i] };
    }

    Result r;
    bool first = true;
    for (auto child : adj[i]) {
        if (first) {
            r = dfs(child);
            first = false;
            continue;
        }

        auto child_res = dfs(child);
        r.sum += child_res.sum;
        r.count += child_res.count;
        r.max = max(child_res.max, r.max);
    }

    ll to_fill = max(0LL, r.count * r.max - r.sum);
    r.sum += a[i];

    if (to_fill < a[i]) {
        r.max += ((a[i] - to_fill + r.count - 1) / r.count);
    }

    return r;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1, p; i < n; i++) {
        cin >> p, p--;
        adj[p].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << dfs(0).max << endl;

    return 0;
}
