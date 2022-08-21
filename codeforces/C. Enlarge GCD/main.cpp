#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>

void get_primes(int n, vector<pair<int, int>> &res) {
    res.clear();
    int r;

    for (int i = 2; i * i <= n; i += i & 1, i++) {
        r = 0;
        while (n % i == 0) {
            r++;
            n /= i;
        }

        if (r > 0)
            res.emplace_back(i, r);
    }

    if (n > 1)
        res.emplace_back(n, 1);
}

void solve() {
    int n;
    scanf("%d", &n);

    int a, g = 0;
    int arr[n];
    unordered_map<int, int> primesfr;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        arr[i] = a;

        if (g == 0) {
            g = a;
        } else {
            g = __gcd(g, a);
        }
    }

    vector<pair<int, int>> primes;

    for (int i = 0; i < n; i++) {
        int a = arr[i] / g;
        get_primes(a, primes);
        for (auto p : primes) {
            primesfr[p.first]++;
        }
    }

    int ans = n;
    for (auto p : primesfr)
        ans = min(ans, n - p.second);

    if (ans == n)
        printf("-1");
    else
        printf("%d", ans);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/home/ms/myp/problem-solving/input", "r", stdin);
#endif
    solve();
    return 0;
}
