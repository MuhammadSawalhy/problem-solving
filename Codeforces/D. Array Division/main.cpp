#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    long long s[n];
    for (int i = 0; i < n; i++) cin >> a[i], s[i] = (long long) a[i] + (i == 0 ? 0 : s[i - 1]);

    map<long long, int> fr;
    map<long long, int> rfr;

    if (s[n - 1] & 1 || n == 1) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        rfr[a[i]]++;
    }

    fr[0] = 1;

    for (int i = 0; i < n; i++) {
        fr[a[i]]++;
        rfr[a[i]]--;
        if (s[i] >= s[n - 1] / 2) {
            if (fr[s[i] - s[n - 1] / 2]) {
                cout << "YES" << endl;
                return 0;
            }
        } else {
            if (rfr[s[n - 1] / 2 - s[i]]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
