#include <bits/stdc++.h>
using namespace std;

const int MX = 256 * 256 - 256 - 256;
bool can[MX + 1];

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    int g = 0;
    can[0] = 1;

    for (int j = 0; j < n; j++) {
        int i;
        cin >> i;
        g = gcd(i, g);

        for (int k = i; k <= MX; k++) can[k] |= can[k - i];
    }

    if (g != 1) {
        cout << 0 << endl;
        return 0;
    }

    int i = MX;
    while (can[i]) i--;
    cout << max(0, i) << endl;

    return 0;
}
