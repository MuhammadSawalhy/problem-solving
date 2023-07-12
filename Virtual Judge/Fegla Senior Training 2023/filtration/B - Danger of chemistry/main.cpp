// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

const int N = 16;
pair<int, long long> dp[N][1 << N];
bool vis[N][1 << N];
int n;
vector<int> a(N);
vector<int> p(18);

vector<pair<int, int>> getswaps(vector<int> a, vector<int> b) {
    vector<pair<int, int>> swaps;
    assert(a.size() == b.size());

    map<int, set<int>> inds;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        inds[a[i]].insert(i);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            inds[a[i]].erase(i);
            continue;
        }

        int j = *inds[b[i]].begin();
        swaps.push_back({i + 1, j + 1});
        inds[a[i]].erase(i);
        inds[a[j]].erase(j);
        swap(a[i], a[j]);
        inds[a[j]].insert(j);
    }

    return swaps;
}

bool comp(vector<int> a, vector<int> b) {
    reverse(all(a));
    reverse(all(b));
    return a < b;
}

void solve(int last, int mask) {
    if (mask == (1 << n) - 1) return;
    auto &ans = dp[last][mask];
    if (vis[last][mask]) return;
    vis[last][mask] = true;

    ans.first = 1e18;

    for (int i = 0; i < n; i++) {
        if (mask >> i & 1 ^ 1) {
            solve(i, mask | (1 << i));
            auto &x = dp[i][mask | (1 << i)];
            long long danger = x.first;
            if (last != n)
                danger += gcd(a[last], a[i]);
            auto newval = x.second;
            newval += 1LL * a[i] * p[n - __builtin_popcount(mask) - 1];
            if (danger < ans.first || danger == ans.first && newval < ans.second) {
                ans.first = danger;
                ans.second = newval;
            }
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(vis, 0, sizeof vis);
    solve(n, 0);

    for (int i = 0; i <= n; i++)
        dp[i][(1 << n) - 1] = {{}, {}};

    long long val = dp[n][0].second;
    vector<int> B;

    while (val) {
        B.push_back(val % 10);
        val /= 10;
    }

    reverse(all(B));
    auto A = vector<int>(a.begin(), a.begin() + n);
    auto swaps = getswaps(A, B);
    cout << swaps.size() << endl;
    for (auto [a, b]: swaps) {
        cout << a << ' ' << b << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    p[0] = 1;
    for (int i = 1; i < 18; i++)
        p[i] = p[i - 1] * 10;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
