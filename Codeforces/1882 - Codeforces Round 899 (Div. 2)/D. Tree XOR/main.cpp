// ﷽
// https://codeforces.com/contest/1882/problem/D
// Codeforces -> Codeforces Round 899 (Div. 2) -> D. Tree XOR

#include <bits/stdc++.h>
#include "../../../instrumentor.hpp"
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
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

const int N = 1e6 + 6;
bool bit[N];
int n, a[N], s[N], ans[N], dp[N][2];
vector<int> adj[N];

void calc(int i, int p) {
    InstrumentationTimer timer("calc");
    s[i] = 1;
    dp[i][0] = dp[i][1] = 0;
    for (auto j: adj[i]) {
        if (j == p) continue;
        calc(j, i);
        s[i] += s[j];
        dp[i][0] += dp[j][bit[i]];
        dp[i][1] += dp[j][bit[i]];
    }

    dp[i][bit[i] ^ 1] += s[i];
}

void setans(int i, int p, int withone, int withzero, int cnt) {
    InstrumentationTimer timer("set ans");
    if (bit[i]) {
        ans[i] = withone + dp[i][0];
    } else {
        ans[i] = withzero + dp[i][0];
    }

    for (auto j: adj[i]) {
        if (j == p) continue;
        withone += dp[j][1];
        withzero += dp[j][0];
    }

    for (auto j: adj[i]) {
        if (j == p) continue;
        if (bit[i]) {
            setans(j, i, withone - dp[j][1], withone - dp[j][1] + n - s[j], cnt + s[i] - s[j]);
        } else {
            setans(j, i, withzero - dp[j][0] + n - s[j], withzero - dp[j][0], cnt + s[i] - s[j]);
        }
    }
}

void solve_bit(int b, bool target) {
    InstrumentationTimer timer("solve bit");
    for (int i = 0; i < n; i++) {
        bit[i] = (a[i] >> b & 1) ^ target;
    }

    // now target is zero
    calc(0, -1);
    setans(0, -1, 0, 0, 0);
}

void solve() {
    InstrumentationTimer timer("solve");
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res[n];
    int cur[n];
    memset(res, 0, sizeof res);

    for (int i = 0; i < 20; i++) {
        solve_bit(i, 1);
        for (int j = 0; j < n; j++)
            cur[j] = ans[j];
        solve_bit(i, 0);
        for (int j = 0; j < n; j++)
            res[j] += min(cur[j], ans[j]) << i;
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << " \n"[i == n - 1];

    for (int i = 0; i < n; i++)
        adj[i].clear();
}

void main_() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    Instrumentor::Get().BeginSession("Profile");

    int t;
    cin >> t;
    while (t--)
        solve();

    Instrumentor::Get().EndSession();
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}

int32_t main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 512 MB stack
    return 0;
}
