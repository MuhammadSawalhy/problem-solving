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

constexpr ll MOD = 1234567891011;

template<int mod = MOD>
struct mint {
private:
    // assume -P <= x < 2P, (it's faster)
    int norm(int x) const {
        if (x < 0)
            return (x % mod + mod) % mod;
        if (x >= mod)
            return x % mod;
        return x;
    }

public:
    __int128 x;
    mint(int32_t x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x)) {}
    ll val() const { return x; }
    mint operator-() const { return mint(norm(mod - x)); }
    mint inv() const {
        assert(x != 0);
        return power(mod - 2);
    }
    mint power(ll b) const {
        mint res = 1, a = x;
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
    mint &operator*=(const mint &rhs) {
        x = (__int128) x * (__int128)rhs.x % mod;
        return *this;
    }
    mint &operator+=(const mint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    mint &operator-=(const mint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    mint &operator/=(const mint &rhs) { return *this *= rhs.inv(); }
    friend mint operator*(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res *= rhs;
        return res;
    }
    friend mint operator+(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res += rhs;
        return res;
    }
    friend mint operator-(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res -= rhs;
        return res;
    }
    friend mint operator/(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, mint &a) {
        ll v;
        is >> v;
        a = mint(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mint &a) {
        return os << a.val();
    }
    friend mint max(mint a, mint b) {
        return a.x > b.x ? a : b;
    }
    friend mint min(mint a, mint b) {
        return a.x < b.x ? a : b;
    }
};

using Z = mint<>;

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
                    temp[i][j] += mat[i][k] % mod * (other.mat[k][j] % mod) % mod;
                    temp[i][j] %= mod;
                }
            }
        }
        mat = temp;
    }

    void operator+=(const matrix &other) {
        assert(m == other.m && n == other.n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                mat[i][j] = ((mat[i][j] + other.mat[i][j]) % mod + mod) % mod;
        }
    }

    void operator-=(const matrix &other) {
        assert(m == other.m && n == other.n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                mat[i][j] = ((mat[i][j] - other.mat[i][j]) % mod + mod) % mod;
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
        matrix I = vv(size, vector<T>(size));
        for (int i = 0; i < size; i++)
            I.mat[i][i] = 1;
        return I;
    }
};

Z f(ll n) {
    matrix mat = vector<vector<__int128>>{{0, 1}, {1, 1}};
    mat.power(n);
    return (ll)mat.mat[0][1];
}

vector<int> a(1e5 + 1);

bool miller_rabin_ptest(unsigned ll n, int k = 6) {
    if (n < 2) return false;
    if (n == 2) return true;
    while (k--) {
        __int128 a = 1LL * rand() * rand() * rand() % (n - 2) + 2;// [2 ... n-1]
        __int128 r = 1;
        for (unsigned ll p = n - 1; p; p >>= 1) {
            if (p & 1) {
                r *= a;
                r %= n;
            }
            a *= a;
            a %= n;
        }
        if (r != 1) return false;
    }
    return true;// probably
}

ll next_power(ll n) {
    int cnt = 0;
    if (n % 2 == 0)
        n += 1;
    else
        n += 2;
    while (true) {
        assert(cnt++ < 1e5);
        if (miller_rabin_ptest(n))
            return n;
        n += 2;
        if (n % 10 == 5)
            n += 2;
    }
}

void processA() {
    int i = 1;
    a[1] = next_power((ll) 1e14);
    while (++i <= 1e5) a[i] = next_power(a[i - 1]);
}

Z b(int n) {
    return f(a[n]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    Z ans = 0;

    processA();

    for (int n = 1; n <= 1e5; n++) {
        if (n % 1000 == 0)
            cout << "processing n = " << n << ", a(n) = " << a[n] << "\r";
        ans += b(n);
    }

    cout << endl;
    cout << ans << endl;

    return 0;
}
