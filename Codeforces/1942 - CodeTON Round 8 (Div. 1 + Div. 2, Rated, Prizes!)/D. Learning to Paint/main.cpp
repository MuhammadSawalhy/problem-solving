// ﷽
// https://codeforces.com/contest/1942/problem/D

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
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> a[i][j];
        }
    }


    vector<int> largest[n + 2];
    largest[n] = {0};
    largest[n + 1] = {0};

    for (int i = n - 1; i >= 0; --i) {
        priority_queue<array<int, 3>> pq;
        pq.push({largest[i + 1].front(), 0, i - 1});
        for (int j = i; j < n; j++) {
            pq.push({largest[j + 2].front() + a[i][j], 0, j});
        }
        while (largest[i].size() < k && pq.size()) {
            auto [val, k, j] = pq.top();
            pq.pop();
            largest[i].push_back(val);
            if (k + 1 < largest[j + 2].size()) {
                int newval = largest[j + 2][k + 1];
                if (j >= i) newval += a[i][j];
                pq.push({newval, k + 1, j});
            }
        }
    }

    for (auto x : largest[0]) {
        cout << x << " ";
    }
    cout << endl;
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
