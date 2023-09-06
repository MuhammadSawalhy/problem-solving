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

#define ll long long
#define all(v) v.begin(), v.end()

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int correct(vector<int> A, vector<int> D) {
    int N = A.size();

    std::vector<std::vector<std::pair<int, int>>> rg(N);
    for (int i = 0; i < N; i++) {
        int L = std::max(0, i - D[i]);
        int R = std::min(N - 1, i + D[i]);
        rg[L].push_back({R, A[i]});
    }

    auto check = [&](int x) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
        for (int i = 0; i < N; i++) {
            for (auto [r, a]: rg[i]) {
                if (a) {
                    q.push({r, a});
                }
            }
            int t = x;
            while (t > 0 && !q.empty()) {
                auto [j, a] = q.top();
                if (j < i) {
                    return false;
                }
                q.pop();
                int m = std::min(a, t);
                a -= m;
                t -= m;
                if (a) {
                    q.push({j, a});
                }
            }
        }
        if (!q.empty()) {
            return false;
        }
        return true;
    };

    int lo = 0, hi = 1E9;
    while (lo < hi) {
        int x = (lo + hi) / 2;
        if (check(x)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }
    return lo;
}

void interact() {
    int n = rand_int(1, 20);
    cout << n << endl;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rand_int(0, 1e9);
        cout << a[i] << ' ';
    }
    cout << endl;

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = rand_int(0, 1e9);
        cout << d[i] << ' ';
    }
    cout << endl;

    int ans;
    cin >> ans;

    assert(ans == correct(a, d));
}

int32_t main(int32_t argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));

    interact();

    return 0;
}
