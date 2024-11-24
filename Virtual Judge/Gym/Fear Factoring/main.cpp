#include <bits/stdc++.h>
using namespace std;

long long calc(long long a) {
    long long ans = 0;
    for (long long i = 1, r; i <= a; i++) {
        r = a / (a / i);
        ans += a / i * (i + r) * (r - i + 1) / 2;
        i = r;
    }
    return ans;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;
    cout << calc(b) - calc(a - 1) << endl;

    return 0;
}
