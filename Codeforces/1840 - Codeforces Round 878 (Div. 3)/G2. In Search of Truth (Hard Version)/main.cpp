// ﷽
// https://codeforces.com/contest/1840/problem/G2

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

const int K = 500, M = 400;
int last = 0;
int a[K];

int ask(int current) {
    debug(current % 6 + 1);
    if (current < last)
        cout << "- " << last - current << endl;
    else
        cout << "+ " << current - last << endl;
    last = current;
    int ans;
    cin >> ans;
    return ans;
}

void printans(int ans) {
    cout << "! " << ans << endl;
    exit(0);
}

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

void solve() {
    cin >> a[0];
    int mx = a[0];

    for (int i = 1; i < K; i++) {
        a[i] = ask(i);
        maxit(mx, a[i]);
        if (a[i] == a[0]) {
            printans(i);
        }
    }

    for (int i = 0; i < M; i++) {
        maxit(mx, ask(rand_int(1, 1e6)));
    }

    mx--;
    while (true) {
        mx += K;
        int x = ask(mx);
        for (int i = 0; i < K; i++) {
            if (a[i] == x) {
                printans(mx - i);
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
