// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

template<typename T = void>
struct OtherType {
    typedef ll type;
};

template<>
struct OtherType<ll> {
    typedef __int128 type;
};

template<typename T, T mod, typename V = typename OtherType<T>::type>
struct mint {
private:
    T norm(T x) const {
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
        return x;
    }

public:
    T x;
    T val() const { return x; }
    mint(V x = 0) : x(norm(x % mod)) {}
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
        return os << a.val();
    }
    friend mint max(mint a, mint b) {
        return a.x > b.x ? a : b;
    }
    friend mint min(mint a, mint b) {
        return a.x < b.x ? a : b;
    }
};

// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using Z = mint<int32_t, MOD>;

class hashed_string {
public:
    // change M and B if you want
    static const ll M = (1LL << 61) - 1;
    static const ll B;

private:
    // pow[i] contains P^i % M
    static vector<mint<ll, M>> pow;
    // hash of the prefixes
    vector<mint<ll, M>> p_hash;


public:
    hashed_string(const string &s) : p_hash(s.size() + 1) {
        while (pow.size() < (int) s.size())
            pow.push_back(pow.back() * B);
        for (int i = 0; i < s.size(); i++)
            p_hash[i + 1] = p_hash[i] * B + s[i];
    }

    auto get_hash(int start, int end) {
        auto raw_val = p_hash[end + 1] - p_hash[start] * pow[end - start + 1];
        return raw_val;
    }
};

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
vector<mint<ll, hashed_string::M>> hashed_string::pow = {1};
const ll hashed_string::B = uniform_int_distribution<ll>(0, M - 1)(rng);

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        string ss = to_string(a[i]);
        while (ss.size() < 5) {
            ss = "0" + ss;
        }
        s += ss;
    }

    reverse(all(s));

    const int MAX = 1e4 + 1;
    vector<vector<int>> primes(MAX);
    for (int i = 2; i < MAX; i++) {
        if (primes[i].size()) continue;
        for (int j = i; j < MAX; j += i) {
            int x = j;
            while (x % i == 0) {
                primes[j].push_back(i);
                x /= i;
            }
        }
    }

    int ans = 0;

    map<int, int> fr;
    int odds = 0;

    auto inc = [&](int p) {
        fr[p]++;
        if (fr[p] & 1) odds++;
        else odds--;
    };

    auto dec = [&](int p) {
        fr[p]--;
        if (fr[p] & 1) odds++;
        else odds--;
    };

    for (int i = 0; i < k; i++) {
        for (auto p: primes[a[i]]) {
            inc(p);
        }
    }

    hashed_string hash(s);
    set<long long> h;

    debug(odds);
    if (odds == 0) {
        h.insert(hash.get_hash(0, k * 5 - 1).x);
        debug(s.substr(0, k * 5));
    }

    for (int i = k; i < n; i++) {
        for (auto p: primes[a[i]]) {
            inc(p);
        }
        for (auto p: primes[a[i - k]]) {
            dec(p);
        }
        debug(i, a[i], odds);
        debug(fr);
        if (odds == 0) {
            debug(s.substr((i - k + 1) * 5, k * 5));
            h.insert(hash.get_hash((i - k + 1) * 5, (i + 1) * 5 - 1).x);
        }
    }

    debug(h);
    cout << h.size() << endl;

    return 0;
}
