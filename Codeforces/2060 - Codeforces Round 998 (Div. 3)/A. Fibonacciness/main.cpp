#include <iostream>
using namespace std;

int main() {
    int t, a1, a2, a4, a5;
    cin >> t;
    while (t--) {
        cin >> a1 >> a2 >> a4 >> a5;
        int res = 0;
        for (int a3 = -300; a3 <= 300; a3++) {
            int cur = 0;
            if (a3 == a1 + a2) ++cur;
            if (a4 == a2 + a3) ++cur;
            if (a5 == a3 + a4) ++cur;
            res = max(res, cur);
        }
        cout << res << '\n';
    }

    return 0;
}

