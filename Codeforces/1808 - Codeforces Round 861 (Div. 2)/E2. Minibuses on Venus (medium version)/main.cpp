// ﷽
// https://codeforces.com/contest/1808/problem/E1

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

int mod;

template<typename T = void> // default
struct BiggerType {
    typedef ll type;
};

template<> // for long long
struct BiggerType<ll> {
    typedef int64_t type;
};

template<typename T, typename V = typename BiggerType<T>::type>
struct mint {
private:
    inline T norm(T x) const {
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
        return x;
    }

public:
    T x;
    mint(T x = 0) : x(norm(x)) {}
    mint(V x) : x(norm(x % mod)) {}
    mint operator-() const { return mint(norm(mod - x)); }
    mint inv() const {
        assert(x != 0);
        return power(mod - 2);
    }
    mint power(long long b) const {
        mint res = 1, a = x;
        for (; b; b >>= 1, a *= a) {
            if (b & 1) res *= a;
        }
        return res;
    }
    mint &operator*=(const mint &rhs) {
        x = (V) x * rhs.x % mod;
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
    friend bool operator==(const mint &lhs, const mint &rhs) {
        return lhs.x == rhs.x;
    }
    friend std::istream &operator>>(std::istream &is, mint &a) {
        T v;
        return is >> v, a = mint(v), is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mint &a) {
        return os << a.x;
    }
    friend mint max(mint a, mint b) {
        return a.x > b.x ? a : b;
    }
    friend mint min(mint a, mint b) {
        return a.x < b.x ? a : b;
    }
};

using Z = mint<int32_t>;

vector<Z> mul(vector<Z> a, vector<Z> b) {
    assert(a.size() == b.size());
    int n = a.size();
    vector<Z> ans(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[(i + j) % n] += a[i] * b[j];
        }
    }
    return ans;
}

vector<Z> powerit(vector<Z> a, int b) {
    vector<Z> ans(a.size());
    ans[0] = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k >> mod;

    Z ans = 0;

    for (int s = 0; s < k; s++) {
        vector<Z> state(k);

        for (int x = 0; x < k; x++) {
            if (2 * x % k == s) continue;
            state[x] = 1;
        }

        ans += powerit(state, n)[s];
    }

    cout << Z(k).power(n) - ans << endl;

    return 0;
}

