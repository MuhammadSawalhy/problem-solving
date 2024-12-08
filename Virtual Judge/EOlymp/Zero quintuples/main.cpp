// ﷽
// https://vjudge.net/problem/EOlymp-7448

#include <bits/stdc++.h>
#include <cstring>
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

constexpr int N = 2002, MX = 40004;
int l[MX], r[MX];
int a[N];

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += 10000;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            r[a[i] + a[j]]++;
        }
    }

    long long ans = 0;
    int five_zeros = 50000;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) r[a[i] + a[j]]--;
        for (int left = 0; left < MX; left++) {
            int sum = left + a[i];
            int rem = five_zeros - sum;
            if (rem >= 0 && rem < MX) {
                ans += 1LL * l[left] * r[rem];
            }
        }
        for (int j = 1; j < i; j++) l[a[i] + a[j]]++;
    }

    cout << ans << endl;

    return 0;
}
