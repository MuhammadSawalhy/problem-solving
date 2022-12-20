#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, p, q;
    cin >> n >> p >> q;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (p == q) {
        // ceiling with (numerator + denomerator - 1)
        cout << (p - 1 + *max_element(a, a + n)) / p << endl;
        return 0;
    }

    auto valid = [&](long long hits) {
        long long needed = 0;
        for (int i = 0; i < n; i++) {
            // ceiling with (numerator + denomerator - 1)
            long long x = (a[i] - hits * q + p - q - 1) / (p - q);
            needed += x;
        }
        return needed <= hits;
    };

    long long s = 0, e = 1e9 + 1;
    while (e - s > 1) {
        int mid = (s + e) / 2;
        if (valid(mid)) {
            e = mid;
        } else {
            s = mid;
        }
    }
    assert(valid(s) == false);
    assert(valid(e) == true);
    cout << e << endl;

    return 0;
}
