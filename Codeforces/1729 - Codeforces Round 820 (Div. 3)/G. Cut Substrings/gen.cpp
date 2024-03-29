#include <bits/stdc++.h>
using namespace std;

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
    cout << 1 << '\n';
    int n = rand_int(1, 10);
    int m = rand_int(1, n);
    cout << string(n, 'a') << endl;
    cout << string(m, 'a') << endl;
}

int main(int argc, char **argv) {
    if (argc > 1) seed(atoi(argv[1]));
    generate();
    return 0;
}
