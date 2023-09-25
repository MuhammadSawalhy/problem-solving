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

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int get_valid(vector<int> &p) {
    int n = p.size();

    std::vector<int> dep(n), deg(n);
    p[0] = -1;
    for (int i = 1; i < n; i++) {
        p[i]--;
        dep[i] = dep[p[i]] + 1;
        deg[p[i]]++;
    }

    int k;
    std::vector<int> col(n);
    if (*std::max_element(dep.begin(), dep.end()) == 1) {
        k = 1;
    } else {
        std::vector<std::vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[p[i]].push_back(i);
        }
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (p[i] == 0) {
                int cnt[2]{};
                auto dfs = [&](auto self, int x) -> void {
                    if (deg[x] == 1) {
                        cnt[dep[x] % 2]++;
                    }
                    for (auto y: adj[x]) {
                        col[y] = col[x] ^ 1;
                        self(self, y);
                    }
                };
                dfs(dfs, i);
                if (cnt[0] && cnt[1]) {
                    ok = false;
                    break;
                } else {
                    col[i] = cnt[0] ? 1 : 0;
                    dfs(dfs, i);
                }
            }
        }

        if (!ok) {
            k = 3;
            for (int i = 1; i < n; i++) {
                col[i] = dep[i] % k;
            }
        } else {
            k = 2;
        }
    }

    return k;
}

void interact() {
    int n = rand_int(3, 100);
    vector<int> p(n);

    for (int i = 1; i < n; i++) {
        p[i] = rand_int(1, i);
    }

    cout << n << endl;
    for (int i = 1; i < n; i++)
        cout << p[i] << ' ';
    cout << endl;
    cout << 1 << endl;
    int k;
    cin >> k;
    assert(k == get_valid(p));
}

int32_t main(int32_t argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));

    int t = 1;
    // cout << t << endl;
    while (t--) {
        interact();
    }

    return 0;
}
