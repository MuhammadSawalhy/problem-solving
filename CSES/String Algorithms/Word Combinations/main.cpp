// ﷽
#include <bits/stdc++.h>

using namespace std;

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

constexpr int MOD = 1000000007; // 998244353

template<int mod = MOD>
struct mint {
private:
    // assume -P <= x < 2P, (it's faster)
    int norm(int x) const {
        if (x < 0)
            x += mod;
        if (x >= mod)
            x -= mod;
        return x;
    }

public:
    int x;
    mint(int32_t x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    int val() const { return x; }
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
        x = (ll)x * rhs.x % mod;
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

const int N = 5000;
Z dp[N + 1];
string s, d;
int n, k;

template<int MAX_SIZE = 26>
struct trie {
    trie *child[MAX_SIZE];
    int count = 0;
    char value;
    bool is_leaf = false;

    trie() {
        for (int i = 0; i < MAX_SIZE; i++)
            child[i] = nullptr;
    }

    ~trie() {
        for (int i = 0; i < MAX_SIZE; i++) {
            if (child[i] == nullptr) continue;
            delete child[i];
        }
    }

    trie *insert(const char *str) {
        count++;
        if (*str == '\0') {
            is_leaf = true;
            return this;
        }

        int cur = *str - 'a';
        if (child[cur] == nullptr) {
            child[cur] = new trie();
            child[cur]->value = *str;
        }

        return child[cur]->insert(str + 1);
    }
    
    void test(int i, int j) {
        if (j >= n) return;
        int k = s[j] - 'a';
        if (child[k] == nullptr) return;
        if (child[k]->is_leaf) dp[i] += dp[j + 1];
        child[k]->test(i, j + 1);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    trie t;
    cin >> s >> k;
    n = s.length();

    for (int i = 0; i < k; i++) {
        cin >> d;
        t.insert(d.c_str());
    }

    dp[n] = 1;

    for (int i = n - 1; ~i; i--) {
        t.test(i, i);
    }

    debug_itr(dp, n + 1);

    cout << dp[0];

    return 0;
}
