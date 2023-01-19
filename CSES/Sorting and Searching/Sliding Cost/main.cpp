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

long long lsum, rsum;
multiset<int> l, r;
int n, k;

long long calc() {
    long long med = *prev(l.end());
    return med * l.size() - lsum + rsum - med * r.size();
}

void balance() {
    int k = (l.size() + r.size());
    while (l.size() > (k + 1) / 2) {
        int v = *prev(l.end());
        r.insert(v);
        l.erase(prev(l.end()));
        lsum -= v;
        rsum += v;
    }
    while (l.size() < (k + 1) / 2) {
        int v = *r.begin();
        l.insert(v);
        r.erase(r.begin());
        lsum += v;
        rsum -= v;
    }
    assert(l.size() == (k + 1) / 2);
}

void erase(int x) {
    auto it = l.find(x);
    if (it != l.end()) {
        l.erase(it);
        lsum -= x;
    } else {
        r.erase(r.find(x));
        rsum -= x;
    }
}

void insert(int x) {
    if (r.lower_bound(x) == r.begin())
        l.insert(x), lsum += x;
    else
        r.insert(x), rsum += x;
    balance();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    // we need the sum of the left half, and sum of the right half
    // when we proceed we update these sums
    // with the value of sums known and the median as well we can do it

    for (int i = 0; i < k; i++) {
        insert(a[i]);
    }

    cout << calc() << " ";

    for (int i = k; i < n; i++) {
        erase(a[i - k]);
        insert(a[i]);
        cout << calc() << " ";
    }

    return 0;
}
