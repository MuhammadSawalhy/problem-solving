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

const int N = 5e4 + 1;
int ans[N];

int n, m;

template<int MAX_SIZE = 26>
struct trie {
    trie *child[MAX_SIZE];
    int count = 0;
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

    trie *insert(vector<int> &v, int i) {
        count++;
        if (i == v.size()) {
            is_leaf = true;
            return this;
        }

        int cur = v[i];
        if (child[cur] == nullptr)
            child[cur] = new trie();

        return child[cur]->insert(v, i + 1);
    }

    void maximize(vector<int> &v, int i, int j) {
        ans[j] = max(ans[j], i - 1);
        if (i == v.size()) return;
        if (child[v[i]] != nullptr)
            child[v[i]]->maximize(v, i + 1, j);
    }
};

void solve() {
    cin >> n >> m;

    int p[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> p[i][j];

    trie<11> t;

    // use i-th perm as index and search for the best one
    // for each one, see what is suitable for it
    // store prefixes and then use each one to maximize

    vector<int> v(m + 1);

    for (int i = 0; i < n; i++) {
        ans[i] = 0;
        for (int j = 0; j < m; j++)
            v[p[i][j]] = j + 1;
        t.insert(v, 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            v[j + 1] = p[i][j];
        t.maximize(v, 1, i);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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
