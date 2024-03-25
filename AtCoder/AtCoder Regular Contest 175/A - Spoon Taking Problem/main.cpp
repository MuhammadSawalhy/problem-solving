// ﷽
// https://atcoder.jp/contests/arc175/tasks/arc175_a

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
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

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

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
using Z = mint<int32_t, MOD>;

int n;
vector<int> a;
string s;

Z solve(bool is_left) {
    int cnt = 0;
    set<int> p;
    for (int i = 0; i < n; i++) p.insert(i);
    p.erase(a[0]);
    for (int i = 1; i < n; i++) {
        int j = a[i];
        int L = (j - 1 + n) % n, R = (j + 1) % n;
        p.erase(j);
        if (!p.count(is_left ? R : L) && s[j] == '?') cnt++;
        if (s[j] == (is_left ? 'R' : 'L') && p.count(is_left ? R : L)) return 0;
    }
    debug(cnt);
    return Z(2).power(cnt);
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
    }

    cin >> s;

    Z ans = 0;

    if (s[a[0]] == '?') {
        ans += solve(true);
        ans += solve(false);
    } else if (s[a[0]] == 'L') {
        ans += solve(true);
    } else {
        ans += solve(false);
    }

    cout << ans << endl;
}

void brute() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
    }

    string s;
    cin >> s;

    int ans = 0;
    for (int mask = 0; mask < 1 << n; mask++) {
        bool ok = true;
        string t;
        for (int i = 0; i < n; i++) {
            t += (mask >> i & 1) ? 'R' : 'L';
            if (s[i] != '?' && t[i] != s[i]) ok = false;
        }

        if (!ok) continue;

        set<char> spoons;
        for (int i = 0; i < n; i++) spoons.insert(i);
        for (auto i: a) {
            int L = i, R = (i + 1) % n;
            if (t[i] == 'L') {
                if (spoons.count(L)) {
                    spoons.erase(L);
                } else if (spoons.count(R)) {
                    spoons.erase(R);
                } else {
                    ok = false;
                }
            } else {
                if (spoons.count(R)) {
                    spoons.erase(R);
                } else if (spoons.count(L)) {
                    spoons.erase(L);
                } else {
                    ok = false;
                }
            }
        }

        if (!ok) continue;
        debug(t);
        ans++;
    }

    debug(bitset<32>(ans));
    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
