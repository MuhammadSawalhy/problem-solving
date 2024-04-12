// ﷽
// https://codeforces.com/contest/1942/problem/E#

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

template<int32_t mod>
struct mint {
    using Z = mint;
    int32_t x;
    mint(int32_t x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    inline static int32_t norm(int32_t x) {
        return x >= mod ? x - mod : (x < 0 ? x + mod : x);
    }
    Z power(ll b) const {
        Z res = 1, a = x;
        for (; b; b >>= 1, a *= a)
            if (b & 1) res *= a;
        return res;
    }
    Z inv() const { return assert(x != 0), power(mod - 2); }
    Z operator-() const { return -x; }
    Z &operator*=(const Z &r) { return *this = (ll) x * r.x; }
    Z &operator+=(const Z &r) { return *this = x + r.x; }
    Z &operator-=(const Z &r) { return *this = x - r.x; }
    Z &operator/=(const Z &r) { return *this *= r.inv(); }
    friend Z operator*(const Z &l, const Z &r) { return Z(l) *= r; }
    friend Z operator+(const Z &l, const Z &r) { return Z(l) += r; }
    friend Z operator-(const Z &l, const Z &r) { return Z(l) -= r; }
    friend Z operator/(const Z &l, const Z &r) { return Z(l) /= r; }
    friend ostream &operator<<(ostream &os, const Z &a) { return os << a.x; }
    friend istream &operator>>(istream &is, Z &a) {
        ll y = 0;
        return is >> y, a = y, is;
    }
};

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
using Z = mint<MOD>;

vector<Z> fact = {1};
vector<Z> fact_inv = {1};

void build_fact(int n = 1e6) {
    while ((int) fact.size() < n + 1)
        fact.push_back(fact.back() * (int) fact.size());
    fact_inv.resize(fact.size());
    fact_inv.back() = fact.back().inv();
    for (int j = fact_inv.size() - 2; fact_inv[j].x == 0; j--)
        fact_inv[j] = fact_inv[j + 1] * (j + 1);
}

Z ncr(int n, int r) {
    if (r > n || r < 0) return 0;
    if ((int) fact.size() < n + 1) build_fact(n);
    return fact[n] * fact_inv[r] * fact_inv[n - r];
}

void solve() {
    int l, n;
    cin >> l >> n;

    Z ans = ncr(l, 2 * n);

    for (int i = 0; i <= l - 2 * n; i += 2) {
        int rem = l - 2 * n - i;
        ans -= ncr(i / 2 + n - 1, n - 1) * ncr(rem + n, n);
    }

    ans *= 2;
    cout << ans << endl;
}

namespace stress
{

const int L = 1e3 + 1;

void brute() {
    int l, n;
    cin >> l >> n;
    Z dp[l + 1][2 * n + 1][2][2];
    dp[0][0][0][0] = 1;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < 2 * n; j++) {
            for (int odd = 0; odd < 2; odd++) {
                for (int last = 0; last < 2; last++) {
                    bool isodd = j % 2 == 1 and (i % 2 - last + 2) % 2 == 0;
                    dp[i + 1][j][odd][last] += dp[i][j][odd][last];
                    dp[i + 1][j + 1][odd | isodd][i & 1] += dp[i][j][odd][last];
                }
            }
        }
    }
    debug(dp[1][0][0][0]);
    debug(dp[1][1][0][0]);
    cout << (dp[l][2 * n][1][1] + dp[l][2 * n][1][0]) * 2 << endl;
}

void brute2() {
    int l, n;
    cin >> l >> n;

    vector<int> perm(l, 1);
    for (int i = 0; i < 2 * n; i++) perm[i] = 0;
    int ans = 0;
    do {
        bool odd = 0;
        for (int i = 0, j = 1; i < n; i++) {
            while (i < sz(perm) && perm[i]) i++;
            j = max(j, i + 1);
            while (j < sz(perm) && perm[j]) j++;
            if (j > sz(perm)) break;
            odd = odd | ((j - i) & 1 ^ 1);
            i = j + 1;
        }
        ans += odd;
    } while (next_permutation(all(perm)));
    cout << ans * 2 << endl;
}

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

void generate() {
    int l = rand_int(3, 5), n = rand_int(1, l / 2);

    cout << l << ' ' << n << endl;
}

string readAllTheFile(const string &filename) {
    ifstream file(filename);
    string content;
    string line;

    if (file.is_open()) {
        while (getline(file, line)) content += line + "\n";
        file.close();
    }
    return content;
}

void stress(int argc, char **argv) {
#ifndef STRESS
    return;
#endif
    if (argc > 1) seed(stoi(argv[1]));
    for (int iter = 0; iter < 100000; iter++) {
        debug(iter);
        FILE *input, *output;

        input = freopen("/tmp/stress-input", "w", stdout);
        generate();
        fclose(input);

        input = freopen("/tmp/stress-input", "r", stdin);
        output = freopen("/tmp/stress-main", "w", stdout);
        solve();
        fclose(input);
        fclose(output);

        input = freopen("/tmp/stress-input", "r", stdin);
        output = freopen("/tmp/stress-brute", "w", stdout);
        brute2();
        fclose(input);
        fclose(output);

        string m = readAllTheFile("/tmp/stress-main");
        string b = readAllTheFile("/tmp/stress-brute");

        if (m != b) {
            string i = readAllTheFile("/tmp/stress-input");
            cerr << "input  --------------------------------" << endl;
            cerr << i << endl;
            cerr << "main   --------------------------------" << endl;
            cerr << m << endl;
            cerr << "brute  --------------------------------" << endl;
            cerr << b << endl;
            exit(1);
        }
    }
    exit(0);
}

} // namespace stress

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    stress::stress(argc, argv);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
