// Date: 10-12-2022
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

#define debug(...)
#define ll long long
#ifdef SAWALHY
#include "debug.hpp"
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    multiset<int> pq;
    multiset<int> p;
    ll sum = 0;

    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + m);

    for (int i = 0; i < k; i++) {
        pq.insert(b[i]);
        sum += b[i];
    }

    for (int i = k; i < m; i++) {
        p.insert(b[i]);
    }

    cout << sum << " ";

    for (int i = m; i < n; i++) {
        if (k == m) {
            sum += a[i];
            sum -= a[i - m];
            cout << sum << " ";
            continue;
        }

        if (p.count(a[i - m])) {
            p.erase(p.find(a[i - m]));
            int mx = *prev(pq.end());
            if (a[i] >= mx) {
                p.insert(a[i]);
            } else {
                p.insert(mx);
                pq.erase(prev(pq.end()));
                pq.insert(a[i]);
                sum += a[i];
                sum -= mx;
            }
        } else {
            debug(a[i], a[i - m], sum);
            pq.erase(pq.find(a[i - m]));
            sum -= a[i - m];
            int mn = *(p.begin());
            if (a[i] <= mn) {
                pq.insert(a[i]);
                sum += a[i];
            } else {
                p.erase(p.begin());
                p.insert(a[i]);
                pq.insert(mn);
                sum += mn;
            }
        }

        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
