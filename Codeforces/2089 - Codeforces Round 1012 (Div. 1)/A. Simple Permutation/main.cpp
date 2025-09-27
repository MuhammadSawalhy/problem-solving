#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

vector<int> primes;
vector<bool> is_prime(1e5 + 5, true);
void sieve() {
    is_prime[1] = false;
    is_prime[0] = false;
    int s = is_prime.size();
    primes.push_back(2);
    for (int i = 4; i < s; i += 2)
        is_prime[i] = false;
    for (int i = 3; i < s; i += 2) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < s; j += i)
                is_prime[j] = false;
        }
    }
}

vector<int> getarr2(int n) {
    vector<int> v;
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    int idx = 0;
    ll x = 0, y = 1, z;
    while (!s.empty() && idx < primes.size()) {
        z = y * primes[idx] - x;
        auto lo = s.upper_bound(z);
        if (lo == s.begin()) {
            idx++;
            continue;
        }
        lo--;
        v.push_back(*lo);
        x += *lo, y++;
        s.erase(lo);
    }
    while (!s.empty()) {
        v.push_back(*s.begin());
        s.erase(s.begin());
    }
    return v;
}

vector<int> getarr(int n) {
    vector<int> v(n + 1);

    set<int> nums;
    for (int i = 1; i <= n; i++) nums.insert(i);

    int j = 0, i = 1;
    for (int sum = 0; j < primes.size() && i <= n;) {
        int p = primes[j];
        int l = i * p - i + 1 - sum, r = i * p - sum;
        auto it = nums.upper_bound(r);
        if (it != nums.begin()) {
            v[i] = *--it;
            nums.erase(v[i]);
            sum += v[i];
            i++;
        } else {
            j++;
        }
    }

    for (; i <= n; i++) {
        auto it = nums.begin();
        v[i] = *it;
        nums.erase(it);
    }

    return vector<int>(v.begin() + 1, v.end());
}

void solve() {
    int n;
    cin >> n;
    auto v = getarr(n);
    for (int i = 0; i < n; i++) cout << v[i] << " \n"[i == n - 1];
}

bool test_prime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}


signed main() {
    cin.tie(0)->sync_with_stdio(0);

    sieve();

    int cnt = 0;
    const int N = 99999;
    auto a = getarr(N);
    for (int i = 1, sum = 0; i <= N; i++) {
        sum += a[i - 1];
        bool is = test_prime((sum + i - 1) / i);
        cnt += is;
    }
    if (cnt < N / 3 - 1)
        debug('!', cnt);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug(t);
        solve();
    }

    return 0;
}
