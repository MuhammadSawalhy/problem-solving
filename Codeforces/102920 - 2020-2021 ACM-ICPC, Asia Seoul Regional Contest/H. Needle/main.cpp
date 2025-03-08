#include <bits/stdc++.h>
using namespace std;

const int MX = 120120;
bitset<MX> u, m, l;

int main() {
    int nu, nm, nl, x;
    cin >> nu;
    while (nu--) cin >> x, x += 30000, u[x] = 1;
    cin >> nm;
    while (nm--) cin >> x, x += 30000, m[x] = 1;
    cin >> nl;
    while (nl--) cin >> x, x += 30000, l[x] = 1;

    int cnt = 0;
    for (int i = 0; i <= 30000; i++) {
        cnt += ((u << i) & m & (l >> i)).count();
        if (i != 0) cnt += ((u >> i) & m & (l << i)).count();
    }

    cout << cnt << endl;
    return 0;
}
