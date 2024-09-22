// ﷽
// https://codeforces.com/group/Rilx5irOux/contest/541733/problem/N

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

typedef valarray<ll> val;
constexpr int hashes = 2;
vector<val> B;
const val M = {
        1000000007,
        1444444447,
        // 998244353,
};

void setB(int n) {
    if (B.size() == 0) {
        mt19937 rng(random_device{}());
        B.assign(2, val(1, hashes));
        for (int i = 0; i < hashes; i++)
            B.back()[i] = uniform_int_distribution<ll>(1, M[i] - 1)(rng);
    }
    while ((int) B.size() <= n) B.push_back(B.back() * B[1] % M);
}

struct Hash {
    vector<val> h;

    Hash(const string &s) : h(s.size() + 1) {
        setB(s.size()), h[0] = val(hashes);
        for (int i = 0; i < (int) s.size(); i++)
            h[i + 1] = (h[i] * B[1] + s[i]) % M;
    }

    auto get(int l, int r) {
        array<ll, hashes> arr;
        val ans = (h[r + 1] - h[l] * B[r - l + 1] % M + M) % M;
        for (int i = 0; i < hashes; i++) arr[i] = ans[i];
        return arr;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    string s, p;
    cin >> s >> p;

    Hash hs(s), hp(p);

    vector<int> ind;
    for (int i = 0; i + m - 1 < n; i++) {
        if (hs.get(i, i + m - 1) == hp.get(0, m - 1)) {
            ind.push_back(i);
        }
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(all(ind), cur) - ind.begin();

        if (j != 0) {
            int nxt = ind[j - 1] + m - 1;
            if (cur < nxt) {
                cur = nxt;
                continue;
            }
        }

        if (j == sz(ind)) break;
        if (ind[j] - cur > k) break;
        cur = ind[j] + m - 1;
    }

    if (cur == n - 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
