// ﷽
// https://codeforces.com/contest/1951/problem/E

#include <bits/stdc++.h>
#include <random>
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

typedef valarray<ll> val;
constexpr int hashes = 2;
vector<val> B;
const val M = {
        1000000007,
        1444444447,
        // 998244353,
};

void setB(int n) {
    if (B.size() == 0) {
        mt19937 rng(random_device{}());
        B.assign(2, val(1, hashes));
        for (int i = 0; i < hashes; i++)
            B.back()[i] = uniform_int_distribution<ll>(1, M[i] - 1)(rng);
    }
    while ((int) B.size() <= n) B.push_back(B.back() * B[1] % M);
}

struct Hash {
    vector<val> h;

    Hash(const string &s) : h(s.size() + 1) {
        setB(s.size()), h[0] = val(hashes);
        for (int i = 0; i < (int) s.size(); i++)
            h[i + 1] = (h[i] * B[1] + s[i]) % M;
    }

    auto get(int l, int r) {
        array<ll, hashes> arr;
        val ans = (h[r + 1] - h[l] * B[r - l + 1] % M + M) % M;
        for (int i = 0; i < hashes; i++) arr[i] = ans[i];
        return arr;
    }
};

bool is_palid(const string &s) {
    int n = sz(s);
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

tuple<bool, int, vector<string>> solve(const string &s) {
    auto r = s;
    reverse(all(r));
    Hash h(s);
    Hash hr(r);
    int n = sz(s);

    auto isp = [&](int l, int r) {
        return h.get(l, r) == hr.get(n - 1 - r, n - 1 - l);
    };

    if (!isp(0, n - 1)) {
        return {true, 1, {s}};
    }

    int i = 0, j = n - 1;
    while (i < j && s[i] == s[0] && s[0] == s[j]) i++, j--;

    for (int i = 0; i < n - 1; i++) {
        if (!isp(0, i) && !isp(i + 1, n - 1)) {
            return {true, 2, {s.substr(0, i + 1), s.substr(i + 1)}};
        }
    }

    return {false, 0, {}};
}

namespace stress
{

bool brute(const string &s) {
    int n = sz(s);
    vector<bool> isvalid(n + 1);
    isvalid[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            isvalid[i] = isvalid[i] || (isvalid[j - 1] && !is_palid(s.substr(j - 1, i - j + 1)));
        }
    }
    return isvalid[n];
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
            s += rand_int('a', 'c');
        return s;
    }
};

string generate() {
    return Gen::str(rand_int(1, 10));
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
    for (int iter = 0; iter < 10000000; iter++) {
        if (iter % 10 == 0)
            cerr << iter << endl;
        FILE *input, *output;

        auto s = generate();
        auto ans = solve(s);
        auto cor = brute(s);

        if (get<0>(ans) != cor) {
            string i = readAllTheFile("/tmp/stress-input");
            cerr << "failed iter: " << iter << endl;
            cerr << "input  --------------------------------" << endl;
            cerr << s << endl;
            cerr << "main   --------------------------------" << endl;
            cerr << get<0>(ans) << endl;
            cerr << "brute  --------------------------------" << endl;
            cerr << cor << endl;
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
    {
        string s;
        cin >> s;
        auto ans = solve(s);
        if (get<0>(ans)) {
            cout << "YES\n";
            cout << get<1>(ans) << '\n';
            for (auto &x : get<2>(ans)) cout << x << ' ' ;
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
