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

    matrix(int n, int m, int ini = 0) : n(n), m(m) { temp = mat = vv(n, vector<T>(m, ini)); }

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
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < other.m; j++) {
                temp[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    temp[i][j] = (temp[i][j] + 1LL * mat[i][k] * other.mat[k][j]) % mod;
                }
            }
        }
        mat = temp;
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

int get_int(char c) {
    if (c <= 'Z') return c - 'A' + 26;
    return c - 'a';
}

pair<int, int> get_ints(string f) {
    return { get_int(f[0]), get_int(f[1]) };
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    matrix mat(m, m, 1);

    string forbidden;
    while (k--) {
        cin >> forbidden;
        auto [x, y] = get_ints(forbidden);
        mat.mat[y][x] = 0;
    }

    mat = mat.power(n - 1) * matrix(m, 1, 1);

    int ans = 0;

    for (int i = 0; i < m; i++)
        ans = (ans + mat.mat[i][0]) % MOD;

    cout << ans;

    return 0;
}
