// ﷽
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

vector<int> p10(10);

void solve() {
    int A, B, C, k;
    cin >> A >> B >> C >> k;

    int state = C == max(A, B) ? 0 : C == 1 + max(A, B) ? 1
                                                        : -1;

    if (state == -1) {
        cout << -1 << '\n';
        return;
    }

    int a = -1;

    for (int i = p10[A - 1]; i < p10[A]; i++) {
        int inc = 0;
        int f = min(p10[B], max(p10[max(A, B)] - i, p10[B - 1]));

        if (state) {
            inc = p10[B] - f;
        } else {
            inc = f - p10[B - 1];
        }

        if (inc >= k) {
            a = i;
            break;
        }

        k -= inc;
    }

    if (a == -1) {
        cout << -1 << endl;
        return;
    }

    int s, e, b;
    int f = min(p10[B], max(p10[max(A, B)] - a, p10[B - 1]));
    b = (state ? f : p10[B - 1]) + k - 1;

    assert(p10[C - 1] <= a + b && a + b < p10[C]);
    cout << a << " + " << b << " = " << a + b << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    p10[0] = 1;
    for (int i = 0; i < 10; i++) {
        p10[i + 1] = p10[i] * 10;
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
