#include <bits/stdc++.h>
using namespace std;

int n, m;

long long getnum(const string &line) {
    for (int i = 0; i < m; i++) {
        if (line[i] < '0' || line[i] > '9') continue;
        return stoll(line.substr(i));
    }
    assert(false);
};

void solve() {
    string lines[n];
    for (int i = 0; i < n; i++) cin >> lines[i];

    long long p = getnum(lines[n - 1]), q = 1;

    assert(n % 2 == 1);
    for (int i = n - 2; i > 0; i -= 2) {
        long long x = getnum(lines[i]), y = getnum(lines[i - 1]);
        swap(p, q);
        p *= y;
        long long g = __gcd(p, q);
        p /= g, q /= g;
        p = q * x + p;
        g = __gcd(p, q);
        p /= g, q /= g;
    }

    cout << p << ' ' << q << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (cin >> n >> m, n && m) {
        solve();
    }

    return 0;
}
