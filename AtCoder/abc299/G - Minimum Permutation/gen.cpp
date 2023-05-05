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

int main(int argc, char *argv[]) {
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));

    int N = gen(2, 10), M = gen(2, N);
    cout << N << " " << M << endl;

    std::vector<int> A(N), lst(M);

    for (int i = 0; i < M; i++) A[i] = i + 1;
    for (int i = M; i < N; i++) A[i] = gen(1, M);

    shuffle(all(A), default_random_engine(rand()));

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
        A[i]--;
        lst[A[i]] = i;
    }

    cout << endl;

    std::set<int> p;
    std::set<std::pair<int, int>> s;
    std::vector<int> ans;
    std::vector<bool> vis(M);
    for (int i = 0; i < M; i++) {
        p.insert(lst[i]);
    }
    int l = 0, r = -1;
    for (int i = 0; i < M; i++) {
        while (r < *p.begin()) {
            r++;
            s.emplace(A[r], r);
        }
        while (true) {
            auto [x, j] = *s.begin();
            s.erase(s.begin());
            if (vis[x]) {
                continue;
            }
            ans.push_back(x);
            p.erase(lst[x]);
            vis[x] = true;
            while (l <= j) {
                s.erase({A[l], l});
                l++;
            }
            break;
        }
    }

    for (int i = 0, x; i < M; i++) {
        cin >> x;
        assert(ans[i] + 1 == x);
    }

    return 0;
}
