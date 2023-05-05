// ﷽
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
#define int    long long
#define all(v) v.begin(), v.end()

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

tuple<int, int, vector<int>> testcase(int i = time(NULL)) {
    srand(i);

    int N = gen(2, 10), M = gen(2, N);

    std::vector<int> A(N);

    for (int i = 0; i < M; i++) A[i] = i + 1;
    for (int i = M; i < N; i++) A[i] = gen(1, M);

    shuffle(all(A), default_random_engine(rand()));

    return {N, M, A};
}

vector<int> stress(int N, int M, vector<int> A) {
    vector<int> lst(N);
    for (int i = 0; i < N; i++) {
        A[i]--;
        lst[A[i]] = i;
    }

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
        ans[i]++;
    }

    return ans;
}

vector<int> solve(int n, int m, vector<int> a) {
    int lst[n + 1];
    vector<int> st, ans;
    vector<bool> vis(n + 1);

    for (int i = 0; i < n; i++) {
        lst[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (vis[a[i]]) continue;

        vector<int> poped;
        while (st.size() && st.back() >= a[i]) {
            poped.push_back(st.back());
            st.pop_back(); // not proved, incorrect
        }

        st.push_back(a[i]);

        if (lst[a[i]] == i) {
            for (auto x: st) {
                ans.push_back(x);
                vis[x] = true;
            }

            st.clear();
            if (poped.size() && poped.back() == a[i]) {
                poped.pop_back();
                while (poped.size())
                    st.push_back(poped.back()), poped.pop_back();
            }
        }
    }

    assert(ans.size() == m);

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    {
        for (int i = 0; i < 100; i++) {
            cout << i << endl;
            auto [N, M, A] = testcase(i);
            auto sol = solve(N, M, A);
            auto str = stress(N, M, A);
            if (sol != str) {
                debug(N, M);
                debug(A);
                debug(sol);
                debug(str);
                break;
            }
        }
        return 0;
    }

    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        auto ans = solve(n, m, a);

        for (auto x: ans)
            cout << x << ' ';
        cout << endl;
    }

    return 0;
}
