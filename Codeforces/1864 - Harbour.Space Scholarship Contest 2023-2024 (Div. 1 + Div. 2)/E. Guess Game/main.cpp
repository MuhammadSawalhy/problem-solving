// ﷽
// https://codeforces.com/contest/1864/problem/E
// Codeforces -> Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2) -> E. Guess Game

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

template<typename T = void> // default
struct BiggerType {
    typedef ll type;
};

template<> // for long long
struct BiggerType<ll> {
    typedef __int128 type;
};

template<typename T, T mod, typename V = typename BiggerType<T>::type>
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
    mint power(T b) const {
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

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
using Z = mint<int32_t, MOD>;

int find_msb(int x) {
    for (int i = 32; i >= 0; i--)
        if (x >> i & 1)
            return i;

    return -1;
}

int count_ones(int x) {
    int cnt = 0;
    while (x) cnt += x & 1, x >>= 1;
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> fr;
    map<int, int> p2;
    map<int, int> msb;

    map<int, int> dp[32];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
        int m = find_msb(a[i]);
        msb[m]++;

        if (m != -1 && a[i] == 1 << m) {
            p2[a[i]]++;
        }

        for (int j = 0; j < 32; j++) {
            dp[j][a[i] >> j]++;
        }
    }

    debug(a);

    Z ans = 0;

    ans += fr[0] * (n);             // one turn for (0, x>=0)
    ans += fr[0] * (n - fr[0]) * 2; // one turn for (x>0, 0)

    debug("zeros", ans);

    // num with itself
    for (auto [x, f]: fr) {
        debug(x, f);
        if (x == 0) continue;
        ans += (f * f) * (count_ones(x) + 1);
    }

    debug("same", ans);

    // with the same msb
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;

        for (int j = 0; j < 32; j++) {
            if (a[i] >> j & 1) continue;
            // 10110?
            // 10111?
            //     ^
            int d = dp[j][(a[i] >> (j + 1)) << 1 | 1];
            int cnt = count_ones(a[i] >> (j + 1));
            if (cnt == 0) continue;
            ans += cnt * 2 * d;
            ans += (cnt * 2 + 1) * d;
        }

        for (int j = 1; j < 32; j++) {
            if (a[i] >> j & 1 ^ 1) continue;
            if (a[i] >> (j - 1) & 1) continue;
            // 10110?
            // 10110?
            //    ^
            int d = dp[j][a[i] >> j] - fr[a[i]];
            assert(d >= 0);
            int cnt = count_ones(a[i] >> (j + 1));
            if (cnt == 0) continue;
            ans += (cnt * 2 + 1) * d;
            // ans += (cnt * 2 + 1) * d; // the other one will count itself
        }
    }


    debug("same msb", ans);

    // with diff msb
    for (int i = 0, j = 0; i < 32; i++) {
        ans += msb[i] * j * 3;
        j += msb[i];
    }

    debug("diff msb", ans);
    cout << ans / (n * n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
