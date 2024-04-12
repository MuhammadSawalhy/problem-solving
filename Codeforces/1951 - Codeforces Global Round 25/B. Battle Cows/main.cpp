// ﷽
// https://codeforces.com/contest/1951/problem/B

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int me = a[k];
    int prev = 0, prev2 = 0, prevcnt = 0;
    int next = n + 1;

    for (int i = 1; i < k; i++) {
        if (a[i] > a[k]) {
            prevcnt++;
        }
    }

    for (int i = 1; i < k; i++) {
        if (a[i] > a[k]) {
            if (prev == 0) {
                prev = i;
            } else if (prev2 == 0) {
                prev2 = i;
            } else {
                break;
            }
        }
    }

    for (int i = k + 1; i <= n; i++) {
        if (a[i] > a[k]) {
            next = i;
            break;
        }
    }

    int ans = 0;
    if (prevcnt == 0) {
        maxit(ans, next - 2);
    } else {
        // put first
        if (prev != 1) {
            maxit(ans, prev - 2);
        }
        if (prev) {
            if (!prev2) {
                prev2 = k;
            }
            // swap with prev
            if (prev != 1) {
                maxit(ans, prev2 - prev + 1 - 2 + 1);
            } else {
                maxit(ans, prev2 - prev + 1 - 2);
            }
        }
    }

    cout << ans << endl;
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
