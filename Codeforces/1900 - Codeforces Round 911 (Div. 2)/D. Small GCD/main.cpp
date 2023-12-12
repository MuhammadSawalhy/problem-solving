// ﷽
// https://codeforces.com/contest/1884/problem/D

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

const int N = 1e5 + 1;
vector<int> facts[N];
long long allf_done[N];
int fr[N], temp[N], cnt[N], allf[N], I;

void solve() {
    int n, nn;
    cin >> n, nn = n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
    }

    sort(all(a));
    debug(a);
    n = unique(all(a)) - a.begin();
    long long ans = 0;

    I = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * fr[a[i]] * (fr[a[i]] - 1) / 2 * (nn - fr[a[i]]) * a[i];
        ans += 1LL * fr[a[i]] * (fr[a[i]] - 1) * (fr[a[i]] - 2) / 6 * a[i];

        for (auto f: facts[a[i]]) {
            if (!allf_done[f])
                allf[I++] = f, allf_done[f] = true;
            temp[f] = cnt[f];
        }

        for (int j = (int) facts[a[i]].size() - 1; j >= 0; j--) {
            int f = facts[a[i]][j];
            ans += 1LL * f * temp[f] * fr[a[i]] * (fr[a[i]] - 1) / 2;
            ans += 1LL * f * temp[f] * fr[a[i]] * (nn - fr[a[i]]);
            debug(a[i], f, temp[f]);
            for (auto ff: facts[f]) {
                if (temp[ff])
                    temp[ff] -= temp[f];
            }
        }

        nn -= fr[a[i]];
        for (auto f: facts[a[i]]) {
            cnt[f] += fr[a[i]];
        }
    }

    cout << ans << '\n';

    for (int i = 0; i < I; i++) {
        int ff = allf[i];
        fr[ff] = 0;
        cnt[ff] = 0;
        allf_done[ff] = false;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            facts[j].push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
