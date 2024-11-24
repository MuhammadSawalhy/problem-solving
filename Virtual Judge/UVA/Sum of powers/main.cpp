// ﷽
// https://vjudge.net/problem/UVA-766

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

struct F {
    long long x, y;
    F(long long x = 0, long long y = 1) {
        long long g = gcd(x, y);
        this->x = x / g;
        this->y = y / g;
    }

    F operator*(const F &b) const {
        return F(x * b.x, y * b.y);
    }

    F operator/(const F &b) const {
        return F(x * b.y, y * b.x);
    }

    F operator+(const F &b) const {
        return F(x * b.y + y * b.x, y * b.y);
    }

    F operator-(const F &b) const {
        return F(x * b.y - y * b.x, y * b.y);
    }
};

F ans[22][22];
int pascal[22][22];

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 0; i <= 21; i++) {
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; j++) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }

    ans[0][1] = 1;

    for (int k = 1; k <= 20; k++) {
        for (int i = 0; i <= k + 1; i++)
            ans[k][i] = pascal[k + 1][i];
        ans[k][0] = pascal[k + 1][0] - 1;

        for (int kk = 0; kk < k; kk++) {
            for (int i = 0; i <= k + 1; i++) {
                ans[k][i] = ans[k][i] - ans[kk][i] * pascal[k + 1][kk];
            }
        }

        for (int i = 0; i <= k + 1; i++) {
            ans[k][i] = ans[k][i] / pascal[k + 1][k];
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        long long l = 1;
        for (int i = k + 1; i >= 0; i--) {
            l = lcm(l, ans[k][i].y);
        }
        cout << l << " ";
        for (int i = k + 1; i >= 0; i--) {
            cout << l / ans[k][i].y * ans[k][i].x << " \n"[i == 0];
        }
        if (t) cout << endl;
    }

    return 0;
}
