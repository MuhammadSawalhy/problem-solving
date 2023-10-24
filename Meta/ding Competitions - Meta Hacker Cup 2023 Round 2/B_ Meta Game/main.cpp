// ﷽
// https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/B?source=codeforces

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

const int N = 2e6 + 6;

int n;
int a[3 * N];
int b[3 * N];

bool check(int offset) {
    if (n & 1) {
        if (a[offset + n / 2] != b[offset + n / 2]) return false;
    } else {
        if (a[offset + n / 2 - 1] > b[offset + n / 2 - 1]) return false;
        if (a[offset + n / 2] < b[offset + n / 2]) return false;
    }

    for (int i = 0; i < n / 2; i++) {
        if (a[offset + i] > b[offset + i]) return false;
    }

    for (int i = n / 2 + (n & 1); i < n; i++) {
        if (a[offset + i] < b[offset + i]) return false;
    }

    for (int i = 0; i < n; i++) {
        if (a[offset + i] != b[offset + n - i - 1]) return false;
    }

    return true;
}

int get_ans_odd() {
    int cnt = 0;

    auto add = [&](int i) {
        cnt += a[i] == b[i];
    };

    auto remove = [&](int i) {
        cnt -= a[i] == b[i];
    };

    for (int i = 0; i < n; i++) {
        add(i);
    }

    for (int i = 0; i < 2 * n; i++) {
        if (cnt == 1) {
            if (check(i)) return i;
        }

        add(i + n);
        remove(i);
    }

    return -1;
}

int get_ans_even() {
    int cnt = 0;

    auto add = [&](int i) {
        cnt += a[i - 1] < b[i - 1] && a[i] > b[i];
    };

    auto remove = [&](int i) {
        cnt -= a[i] < b[i] && a[i + 1] > b[i + 1];
    };

    for (int i = 1; i < n; i++) {
        add(i);
    }

    for (int i = 0; i < 2 * n; i++) {
        if (cnt == 1) {
            if (check(i)) return i;
        }

        add(i + n);
        remove(i);
    }

    return -1;
}

int get_ans() {
    if (n & 1) return get_ans_odd();
    return get_ans_even();
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        a[i + n] = b[i];
        b[i + n] = a[i];
        a[i + n * 2] = a[i];
        b[i + n * 2] = b[i];
    }

    // debug(n);
    // debug_itr(a, 3 * n);
    // debug_itr(b, 3 * n);
    cout << get_ans() << endl;
}

void main_() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
        cout << "Case #" << tc << ": ", solve();
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *) malloc(stsize);
    send = stack + stsize - 16;
    send = (char *) ((uintptr_t) send / 16 * 16);
    asm volatile(
            "mov %%rsp, (%0)\n"
            "mov %0, %%rsp\n"
            :
            : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n"
                 :
                 : "r"(send));
    free(stack);
}

int32_t main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024 / 2); // run with a 512 MB stack
    return 0;
}
