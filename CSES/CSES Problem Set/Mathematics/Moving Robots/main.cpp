// ﷽
// https://cses.fi/problemset/task/1726

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

void solve() {
    int k;
    cin >> k;

    double here[8][8];
    memset(here, 0, sizeof here);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            here[i][j] = 1;
        }
    }

    auto isvalid = [&](int i, int j) {
        if (i < 0 || j < 0 || i >= 8 || j >= 8) return 0;
        return 1;
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            vector<vector<double>> p(8, vector<double>(8));
            p[i][j] = 1;
            for (int kk = 0; kk < k; kk++) {
                vector<vector<double>> newp(8, vector<double>(8));

                for (int ii = 0; ii < 8; ii++) {
                    for (int jj = 0; jj < 8; jj++) {
                        int cnt = 0;
                        for (int d = 0; d < 4; d++) {
                            cnt += isvalid(ii + di[d], jj + dj[d]);
                        }
                        for (int d = 0; d < 4; d++) {
                            if (isvalid(ii + di[d], jj + dj[d])) {
                                newp[ii + di[d]][jj + dj[d]] += p[ii][jj] / cnt;
                            }
                        }
                    }
                }

                swap(newp, p);
            }

            for (int ii = 0; ii < 8; ii++) {
                for (int jj = 0; jj < 8; jj++) {
                    here[ii][jj] *= 1 - p[ii][jj];
                }
            }
        }
    }

    double ans = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ans += here[i][j];
        }
    }

    cout << fixed << setprecision(6) << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    while (t--)
        solve();

    return 0;
}
