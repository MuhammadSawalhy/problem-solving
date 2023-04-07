// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

constexpr ll MOD = 1e4 + 7;

template<typename T = int, int mod = MOD>
struct matrix {
    typedef vector<vector<T>> vv;
    vv mat;
    int n, m;

    matrix(vv mat) : mat(mat) {
        n = mat.size();
        m = mat[0].size();
    }

    matrix(int n, int m, int ini = 0) : n(n), m(m) { mat = vv(n, vector<T>(m, ini)); }

    matrix operator*(const matrix &other) const {
        matrix mat = *this;
        return mat *= other;
    }

    matrix operator+(const matrix &other) const {
        matrix mat = *this;
        return mat += other;
    }

    matrix operator-(const matrix &other) const {
        matrix mat = *this;
        return mat -= other;
    }

    matrix &operator*=(const matrix &other) {
        assert(m == other.n);
        vector<vector<T>> temp(n, vector<T>(other.m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < other.m; j++) {
                for (int k = 0; k < m; k++) {
                    temp[i][j] = (temp[i][j] + 1LL * mat[i][k] * other.mat[k][j]) % mod;
                }
            }
        }
        mat = temp;
        m = other.m;
        return *this;
    }

    matrix &operator+=(const matrix &other) {
        assert(m == other.m && n == other.n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                mat[i][j] = ((mat[i][j] + other.mat[i][j]) % mod + mod) % mod;
        }
        return *this;
    }

    matrix &operator-=(const matrix &other) {
        assert(m == other.m && n == other.n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                mat[i][j] = ((mat[i][j] - other.mat[i][j]) % mod + mod) % mod;
        }
        return *this;
    }

    matrix power(ll p) {
        assert(p >= 0);
        matrix m = *this;
        matrix res = identity(n);
        for (; p; p >>= 1, m *= m)
            if (p & 1) res *= m;
        return res;
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
            d += sign * mat[0][i] * submat.det();
            sign *= -1;
        }

        return d;
    }

    static matrix identity(int size) {
        matrix I = vv(size, vector<T>(size));
        for (int i = 0; i < size; i++)
            I.mat[i][i] = 1;
        return I;
    }
};

int dp[1001], cnt[1001];

matrix<> mat = vector<vector<int>>{
        {0, 1, 0, 0},
        {2, 2, 0, 0},
        {0, 0, 0, 1},
        {2, 2, 2, 2},
};

matrix<> ini = vector<vector<int>>{
        {1},
        {2},
        {1},
        {4},
};

int solve(int n) {
    if (n < 2) return cnt[n];
    return (mat.power(n - 1) * ini).mat[3][0];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    dp[0] = 1, dp[1] = 2;
    cnt[0] = 1, cnt[1] = 4;
    for (int i = 2; i < 1001; i++) {
        dp[i] = 2 * (dp[i - 1] + dp[i - 2]) % MOD;
        cnt[i] = 2 * (cnt[i - 2] + cnt[i - 1] + dp[i - 1] + dp[i - 2]) % MOD;
        assert(cnt[i] == solve(i));
    }

    int n;
    while (cin >> n, n != -1)
        cout << solve(n) << '\n';

    return 0;
}
