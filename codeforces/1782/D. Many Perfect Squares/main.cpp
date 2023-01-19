// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 51;
int n, a[N];

vector<int> primes;

bool perfect(long long x) {
    long long sq = sqrtl(x);
    return sq * sq == x;
}

vector<long long> x;

void solve(int i, int j) {
    long long d = a[j] - a[i];
    map<int, int> pfact;
    for (auto p: primes)
        while (d > 1 && d % p == 0)
            pfact[p]++, d /= p;

    if (d != 1) pfact[d]++;

    vector<int> facts{1};
    for (auto [p, fr]: pfact) {
        int sz = facts.size();
        long long f = 1;
        while (fr--) {
            f *= p;
            for (int i = 0; i < sz; i++) {
                facts.push_back(facts[i] * f);
            }
        }
    }

    d = a[j] - a[i];
    for (auto f: facts) {
        long long g = d / f;
        if ((g + f) % 2 == 0) {
            long long tj = (g + f) * (g + f) / 4, ti = tj - d;
            if (perfect(ti) && perfect(tj) && ti >= a[i]) {
                assert(ti - a[i] == tj - a[j]);
                x.push_back(ti - a[i]);
            }
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    x.clear();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            solve(i, j);
        }
    }

    int ans = 1;

    for (long long y: x) {
        int c = 0;
        for (int i = 0; i < n; i++)
            c += perfect(a[i] + y);
        ans = max(ans, c);
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<bool> isprime(1e5, true);
    for (int i = 2; i < 1e5; i++) {
        if (!isprime[i]) continue;
        primes.push_back(i);
        for (int j = i * i; j < 1e5; j += i)
            isprime[j] = false;
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
