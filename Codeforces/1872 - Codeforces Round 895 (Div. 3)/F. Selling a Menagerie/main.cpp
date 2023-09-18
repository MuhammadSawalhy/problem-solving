// ﷽
// https://codeforces.com/contest/1872/problem/F
// Codeforces -> Codeforces Round 895 (Div. 3) -> F. Selling a Menagerie

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 1e5 + 5;
int n;
int a[N];
int c[N], indeg[N];
bool instack[N], incycle[N], vis[N];
vector<int> st;
vector<int> ans, aaa, bbb;

void dfs(int i) {
    if (instack[i]) {
        ll y = 1e18;
        int j = st.size() - 1;
        int J = -1;
        while (st[j] != i) j--;
        for (int k = j; k < st.size(); k++) {
            incycle[st[k]] = true;
            if (c[st[k]] < y) {
                y = c[st[k]];
                J = k;
            }
        }

        for (int k = 0; k < j; k++) {
            ans.push_back(st[k]);
        }

        rotate(st.begin() + j, st.begin() + J, st.end());

        if (a[st[j]] == a[st.back()]) {
            reverse(st.begin() + j, st.end());
        } else {
            rotate(st.begin() + j, st.begin() + j + 1, st.end());
        }

        for (int k = j; k < st.size(); k++) {
            aaa.push_back(st[k]);
        }
        return;
    }

    if (vis[i]) {
        for (int j = 0; j < st.size(); j++)
            ans.push_back(st[j]);
        return;
    }

    vis[i] = true;
    instack[i] = true;
    st.push_back(i);

    dfs(a[i]);

    st.pop_back();
    instack[i] = false;
}

void dfs2(int i) {
    if (incycle[i] || vis[i]) return;
    vis[i] = true;
    dfs2(a[i]);
    bbb.push_back(i);
}

void solve() {
    cin >> n;
    ans.clear();
    aaa.clear();
    bbb.clear();

    for (int i = 0; i < n; i++)
        indeg[i] = 0, vis[i] = false, incycle[i] = false;

    for (int i = 0; i < n; i++)
        cin >> a[i], indeg[--a[i]]++;

    for (int i = 0; i < n; i++)
        cin >> c[i];

    debug("----------------------");
    debug(n);

    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) dfs(i);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }

    for (int i = 0; i < n; i++)
        vis[i] = false;

    debug(ans);
    debug_itr(incycle, n);

    for (int i = 0; i < ans.size(); i++) {
        assert(!incycle[ans[i]]);
        if (vis[ans[i]]) continue;
        dfs2(ans[i]);
    }
    reverse(all(bbb));

    for (auto x: bbb) cout << x + 1 << ' ';
    for (auto x: aaa) cout << x + 1 << ' ';
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
