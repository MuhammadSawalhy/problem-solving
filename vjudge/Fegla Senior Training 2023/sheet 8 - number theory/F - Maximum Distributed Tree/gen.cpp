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
#define all(v) v.begin(), v.end()

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

string genstr(int len) {
    string s;
    for (int i = 0; i < len; i++)
        s += 'a' + gen(0, 25);
    return s;
}

vector<int> gen_tree_parents(int n, int root) {
    // in a tree, each node other than the root
    // has exactly one parent
    assert(1 <= root && root <= n);
    vector<int> parents(n + 1, -1);
    vector<int> order(n + 1);
    if (n == 1) return parents;
    iota(all(order), 0);
    shuffle(order.begin() + 1, order.end(),
            default_random_engine(rand()));
    swap(order[1], *find(all(order), root));
    for (int i = 2; i <= n; i++)
        parents[order[i]] = order[gen(1, i - 1)];
    return parents;
}

vector<pair<int, int>> gen_tree(int n, int root = -1) {
    if (root == -1) root = gen(1, n);
    auto parents = gen_tree_parents(n, root);
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; i++) {
        if (i == root) continue;
        edges.emplace_back(i, parents[i]);
    }
    assert(edges.size() == n - 1);
    return edges;
}

int main(int argc, char *argv[]) {
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
    int t = 1;
    cout << t << endl;
    while (t--) {
        int n = gen(1, 100) + 1;
        cout << n << endl;
        for (auto [a, b]: gen_tree(n))
            cout << a << ' ' << b << endl;
        int m = gen();
        cout << m << endl;
        for (int i = 0; i < m; i++)
            cout << gen(2, 1e5) << ' ';
        cout << endl;
    }
    return 0;
}
