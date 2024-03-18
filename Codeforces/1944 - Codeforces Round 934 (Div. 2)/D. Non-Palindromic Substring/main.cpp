// ﷽
// https://codeforces.com/contest/1944/problem/D

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

constexpr int HASH_ITER = 3;
vector<valarray<ll>> B;
const valarray<ll> M = {
        1000000007,
        1444444447,
        998244353,
};

void setB(int n) {
    if (B.size() == 0) {
        // random bases
        mt19937 rng(random_device{}());
        valarray<ll> v(HASH_ITER);
        B.push_back(v = 1);
        for (int i = 0; i < HASH_ITER; i++)
            v[i] = uniform_int_distribution<ll>(1, M[i] - 1)(rng);
        B.push_back(v);
    }
    while ((int) B.size() <= n) B.push_back(B.back() * B[1] % M);
}

struct Hash {
    vector<valarray<ll>> h;

    Hash(const string &s) : h(s.size() + 1) {
        setB(s.size());
        h[0] = valarray<ll>(HASH_ITER);
        for (int i = 0; i < s.size(); i++)
            h[i + 1] = (h[i] * B[1] + s[i]) % M;
    }

    auto get(int l, int r) {
        auto ans = (h[r + 1] - h[l] * B[r - l + 1] % M + M) % M;
        array<ll, HASH_ITER> arr;
        for (int i = 0; i < HASH_ITER; i++)
            arr[i] = ans[i];
        return arr;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> same(n + 1), alter(n + 1);
    for (int i = 1; i < n; i++) {
        if (i - 2 >= 0 && s[i] != s[i - 2]) {
            alter[i + 1] = 1;
        }
        if (i - 1 >= 0 && s[i] != s[i - 1]) {
            same[i + 1] = 1;
        }

        alter[i + 1] += alter[i];
        same[i + 1] += same[i];
    }

    Hash h(s);
    auto r = s;
    reverse(all(r));
    Hash hr(r);

    auto ispalin = [&](int l, int r) {
        return h.get(l - 1, r - 1) == hr.get(n - r, n - l);
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;

        if (len == 1) {
            cout << 0 << endl;
            continue;
        }

        int ans = 0;
        if (same[l] != same[r]) {
            // all evens
            int x = len / 2;
            ans = x * (x + 1);
            if (len % 2 == 0 && ispalin(l, r)) {
                ans -= len;
            }
        }

        if (len >= 3 && alter[l + 1] != alter[r]) {
            // sum of all odd number from 1 to len
            int x = (len + 1) / 2;
            ans += x * (x + 1) - x;
            ans--;
            if (len % 2 == 1 && ispalin(l, r)) {
                ans -= len;
            }
        }

        cout << ans << endl;
    }
}

bool ispalin(string &s, int l, int r) {
    while (l <= r) {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

void brute() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int len = r - l + 1;

        int ans = 0;
        for (int i = 2; i <= len; i++) {
            bool ok = false;
            for (int j = l; j + i - 1 <= r; j++) {
                if (!ispalin(s, j, j + i - 1)) ok = true;
            }
            ans += ok * i;
        }

        cout << ans << endl;
    }
}

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

struct Gen {
    static vector<int> perm(int n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = i;
        random_shuffle(a.begin(), a.end());
        return a;
    }

    static vector<int> tree_parents(int n) {
        vector<int> p(n - 1);
        auto a = perm(n);
        // a.begin(), node 1, is the root
        random_shuffle(a.begin() + 1, a.end());
        for (int i = 1; i < n; i++)
            p[i - 1] = a[rand_int(0, i - 1)] + 1;
        return p;
    }

    static vector<pair<int, int>> tree_edges(int n) {
        auto a = perm(n);
        vector<pair<int, int>> edges;
        for (int i = 1; i < n; i++)
            edges.push_back({a[i] + 1, a[rand_int(0, i - 1)] + 1});
        return edges;
    }


    static vector<vector<int>> tree_adj(int n) {
        vector<vector<int>> adj(n);
        for (auto [u, v]: tree_edges(n)) {
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    static string str(int n) {
        string s;
        for (int i = 0; i < n; i++)
            s += rand_int('a', 'z');
        return s;
    }
};

void generate() {
    int n = rand_int(2, 20), q = rand_int(1, 5);

    cout << n << ' ' << q << endl;
    cout << Gen::str(n) << endl;

    while (q--) {
        int l = rand_int(1ll, n - 1);
        int r = rand_int(l + 1, n);
        cout << l << ' ' << r << endl;
    }
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
        brute();
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

int32_t main(int32_t argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    // stress(argc, argv);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
