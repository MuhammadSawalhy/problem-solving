// ﷽
// https://codeforces.com/contest/1977/problem/D

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

    val get(int l, int r) const {
        val ans = (h[r + 1] - h[l] * B[r - l + 1] % M + M) % M;
        return ans;
    }
};

array<ll, hashes> to_array(const val &v) {
    array<ll, hashes> ans;
    for (int i = 0; i < hashes; i++)
        ans[i] = v[i];
    return ans;
}

array<ll, hashes> get_hash(const string &s, const Hash &h, int i, char newval) {
    setB(s.size());
    val curval = Hash(string(1, newval)).get(0, 0);
    if (s.size() == 1) {
        return to_array(curval);
    }
    if (i == 0) {
        return to_array((curval * B[s.size() - 1] % M + h.get(1, s.size() - 1)) % M);
    }
    if (i == s.size() - 1) {
        return to_array((h.get(0, s.size() - 2) * B[1] % M + curval) % M);
    }
    return to_array((h.get(0, i - 1) * B[s.size() - i] % M + curval * B[s.size() - i - 1] % M + h.get(i + 1, s.size() - 1)) % M);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    map<array<ll, hashes>, int> fr;

    string ans;
    int mx = -1;

    for (int i = 0; i < m; i++) {
        string cur;
        bool allzeros = 1;
        for (int j = 0; j < n; j++) {
            cur += s[j][i];
            allzeros &= cur.back() == '0';
        }

        Hash h(cur);

        if (allzeros) {
            for (int j = 0; j < n; j++) {
                auto x = get_hash(cur, h, j, '1');
                fr[x]++;
                if (fr[x] > mx) {
                    mx = fr[x];
                    ans = cur;
                    ans[j] = '1';
                }
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (cur[j] == '1') {
                    auto x = get_hash(cur, h, j, '0');
                    fr[x]++;
                    if (fr[x] > mx) {
                        mx = fr[x];
                        ans = cur;
                        ans[j] = '0';
                    }
                } else {
                    auto x = get_hash(cur, h, j, '1');
                    fr[x]++;
                    if (fr[x] > mx) {
                        mx = fr[x];
                        ans = cur;
                        ans[j] = '1';
                    }
                }
            }
        }
    }

    cout << mx << '\n';
    cout << ans << '\n';
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
