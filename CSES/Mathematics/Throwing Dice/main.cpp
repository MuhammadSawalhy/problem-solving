// ﷽
#include <bits/stdc++.h>

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

constexpr ll MOD = 1e9 + 7;

template<typename T = int, int mod = MOD>
struct matrix {
    typedef vector<vector<T>> vv;
    vv mat, temp;
    int n, m;

    matrix(vv mat) : mat(mat) {
        n = mat.size();
        m = mat[0].size();
        temp = mat;
    }

    matrix(int n, int m) : n(n), m(m) { temp = mat = vv(n, vector<T>(m)); }

    void operator*=(const matrix &other) {
        assert(m == other.n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < other.m; j++) {
                temp[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    temp[i][j] += mat[i][k] * other.mat[k][j] % mod;
                    temp[i][j] %= mod;
                }
            }
        }
        mat = temp;
    }

    void operator+=(const matrix &other) {
        assert(m == other.m && n == other.n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] += other.mat[i][j];
                mat[i][j] %= mod;
            }
        }
    }

    void operator-=(const matrix &other) {
        assert(m == other.m && n == other.n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] -= other.mat[i][j];
                mat[i][j] %= mod;
            }
        }
    }

    void power(ll p) {
        assert(p >= 0);
        matrix res = identity(n);
        matrix m = *this;
        for (; p; p>>=1) {
            if (p & 1) res *= m;
            m *= m;
        }
        mat = res.mat;
    }

    ll det() {
        assert(n == m);
        if (n == 2)
            return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
        ll d = 0;
        int sign = 1;
        for (int i = 0; i < n; i++) {
            matrix submat(n - 1, n - 1);
            for (int j = 0; j < n - 1; j++) {
                int x = 0;
                for (int k = 0; k < n; k++) {
                    if (i == k)
                        continue;
                    submat.mat[j][x++] = mat[j + 1][k];
                }
            }
            debug(sign * mat[0][i], submat.mat);
            d += sign * mat[0][i] * submat.det();
            sign *= -1;
        }

        return d;
    }

    static matrix identity(int size) {
        matrix I = vv(size, vector<ll>(size));
        for (int i = 0; i < size; i++)
            I.mat[i][i] = 1;
        return I;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    matrix mat = vector<vector<int>>{
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1},
    };

    vector<vector<int>> dp(6, vector<int>(1));
    for (int i = 1; i <= 6; i++) {
        dp[i - 1][0] = 1;
        for (int j = i - 1; j >= max(1LL, i - 6); j--) {
            dp[i - 1][0] += dp[j - 1][0];
        }
    }

    matrix ini = dp;

    int n;
    cin >> n;

    if (n <= 6) {
        cout << dp[n - 1][0] << endl;
        return 0;
    }

    mat.power(n - 6);
    mat *= ini;

    cout << mat.mat[5][0] << endl;

    return 0;
}
