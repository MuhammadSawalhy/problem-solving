// ﷽
// https://vjudge.net/problem/UVA-10679

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

struct AhoCorasick {
    static constexpr int K = 100;
    vector<vector<int>> child, id;
    vector<int> fail;

    AhoCorasick() { add_node(); }

    int add_node() {
        id.push_back({}), fail.push_back(0);
        child.push_back(vector<int>(K));
        return child.size() - 1;
    }

    int insert(const string &s, int ind) {
        int cur = 0; // root
        for (auto c: s) {
            if (child[cur][c - 'A'] == 0)
                child[cur][c - 'A'] = add_node();
            cur = child[cur][c - 'A'];
        }
        id[cur].push_back(ind);
        return cur;
    }

    int go(int cur, int nxt) {
        while (cur && !child[cur][nxt]) cur = fail[cur];
        return child[cur][nxt];
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < K; i++)
            if (child[0][i]) q.push(child[0][i]);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nxt = 0; nxt < K; nxt++) {
                if (!child[cur][nxt]) continue;
                fail[child[cur][nxt]] = go(fail[cur], nxt);
                q.push(child[cur][nxt]);
            }
        }
    }
};

void solve() {
    string s;
    cin >> s;

    int n;
    cin >> n;
    string x;
    AhoCorasick ac;

    vector<bool> ans(n);

    for (int i = 0; i < n; i++) {
        cin >> x;
        ac.insert(x, i);
    }

    ac.build();

    debug(s);
    int cur = 0;
    for (auto c: s) {
        debug(c);
        cur = ac.go(cur, c - 'A');
        if (!cur) continue;
        int temp = cur;
        debug(cur);
        while (temp) {
            for (auto i: ac.id[temp]) ans[i] = true;
            temp = ac.fail[temp];
        }
    }

    for (auto x: ans) {
        if (x) {
            cout << "y" << endl;
        } else {
            cout << "n" << endl;
        }
    }
}

void brute() {
    string s;
    cin >> s;
    int n;
    cin >> n;

    string x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        bool ok = false;
        for (int j = 0; j + sz(x) <= sz(s); j++) {
            if (s.substr(j, sz(x)) == x) {
                ok = true;
            }
        }
        if (ok)
            cout << "y" << endl;
        else
            cout << "n" << endl;
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

    cout << Gen::str(n) << endl;
    cout << q << endl;

    while (q--) {
        cout << Gen::str(rand_int(1, 3)) << endl;
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

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // stress(argc, argv);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
