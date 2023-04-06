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

    matrix(int n, int m) : n(n), m(m) { temp = mat = vv(n, vector<T>(m)); }

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
        swap(temp, mat);
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    matrix mat(n + 3, n + 3);
    matrix ini(n + 3, 1);

    // to calculate a[n + 1]
    //
    // shift from a[2] to a[n] so they will be a[1] to a[n - 1]
    // and then calculate a[n]
    // keep track of i, i ^ 2 and put p,q,r in the matrix

    for (int i = 0; i < n - 1; i++) {
        mat.mat[i][i + 1] = 1;
    }

    // a
    for (int i = 0; i < n; i++) {
        cin >> ini.mat[i][0];
    }

    // c
    for (int i = n - 1; ~i; i--) {
        cin >> mat.mat[n - 1][i];
    }

    if (k < n) {
        cout << ini.mat[k][0] << endl;
        return 0;
    }

    cin >> mat.mat[n - 1][n + 0]; // p
    cin >> mat.mat[n - 1][n + 1]; // q
    cin >> mat.mat[n - 1][n + 2]; // r

    // initial values
    ini.mat[n + 0][0] = 1;    // 1
    ini.mat[n + 1][0] = n;    // i
    ini.mat[n + 2][0] = n*n;  // i^2

    // 1 = 1
    mat.mat[n + 0][n + 0] = 1;

    // i = i + 1
    mat.mat[n + 1][n + 0] = 1; 
    mat.mat[n + 1][n + 1] = 1;

    // i^2 = i^2 + 2 * i + 1 = (i + 1)^2
    mat.mat[n + 2][n + 0] = 1;
    mat.mat[n + 2][n + 1] = 2;
    mat.mat[n + 2][n + 2] = 1;

    mat = mat.power(k - n + 1) * ini;

    cout << mat.mat[n - 1][0] << endl;

    return 0;
}
