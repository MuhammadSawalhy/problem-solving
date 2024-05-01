// ﷽
// https://cses.fi/problemset/task/1670

#include <bits/stdc++.h>
#include <unordered_map>
#pragma GCC optimize("Ofast")
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

map<vector<int>, int> memo;

int p10[9];
int vec[3][3];
unordered_map<int, bool> vis;

int get(int v, int i) {
    return v / p10[i] % 10;
}

void tovec(int x) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vec[i][j] = get(x, 8 - (i * 3 + j));
        }
    }
}

int fromvec() {
    int res = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res *= 10;
            res += vec[i][j];
        }
    }
    return res;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    p10[0] = 1;
    for (int i = 1; i <= 8; i++) p10[i] = p10[i - 1] * 10;

    int v = 0, start = 0;
    for (int i = 0, x; i < 9; i++) {
        cin >> x;
        v *= 10;
        v += x;
        start *= 10;
        start += i + 1;
    }

    queue<pair<int, int>> q;
    vis[start] = true;
    q.push({start, 0});

    while (q.size()) {
        auto [t, d] = q.front();
        q.pop();

        if (t == v) {
            cout << d << endl;
            return 0;
        }

        tovec(t);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j < 2) {
                    // swap with the right
                    swap(vec[i][j], vec[i][j + 1]);
                    int x = fromvec();
                    if (!vis[x]) {
                        vis[x] = true;
                        q.push({x, d + 1});
                    }
                    swap(vec[i][j], vec[i][j + 1]);
                }

                if (i < 2) {
                    // swap with the down
                    swap(vec[i][j], vec[i + 1][j]);
                    int x = fromvec();
                    if (!vis[x]) {
                        vis[x] = true;
                        q.push({x, d + 1});
                    }
                    swap(vec[i][j], vec[i + 1][j]);
                }
            }
        }
    }

    return 0;
}
