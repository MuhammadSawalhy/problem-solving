#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);

    vector<pair<int, int>> primes;

    int r;
    for (int i = 2; i * i <= g; i += i & 1, i++) {
        r = 0;
        while (g % i == 0) {
            r++;
            g /= i;
        }

        if (r)
            primes.emplace_back(i, r);
    }

    if (g > 1)
        primes.emplace_back(g, 1);

    vector<int> factors{1};

    for (auto [p, r]: primes) {
        int pp = 1;
        int j = factors.size();
        while (r--) {
            pp *= p;
            for (int i = 0; i < j; i++) {
                factors.push_back(factors[i] * pp);
            }
        }
    }

    sort(factors.begin(), factors.end());

    // for(int i = 0; i < factors.size(); i++)
    // cout << factors[i] << " ";
    // cout << endl;

    int q;
    cin >> q;
    while (q--) {
        int l, h;
        cin >> l >> h;
        auto i = lower_bound(factors.begin(), factors.end(), l);
        auto j = upper_bound(factors.begin(), factors.end(), h);
        if (i == j) {
            cout << -1 << endl;
        } else {
            j--;
            cout << *j << endl;
        }
    }
}
