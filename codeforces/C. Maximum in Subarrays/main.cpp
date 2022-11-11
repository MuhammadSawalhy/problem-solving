#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
      
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<long long> fr(n, 1);
    for (auto &i : a) scanf("%d", &i);
    
    stack<pair<int, int>> s; // value, index
    s.push({ a[0], 0 });
    for (int i = 1; i < n; i++) {
        if (a[i] <= s.top().first) {
            s.push({a[i], i});
            continue;
        }
        
        long long f = 0;
        while (!s.empty() && a[i] > s.top().first) {
            long long temp = fr[s.top().second];
            fr[s.top().second] += f * (temp - 1) + f;
            f += temp;
            s.pop();
        }

        fr[i] += f;
        s.push({a[i], i});
    }
    
    long long f = fr[s.top().second];
    s.pop();
    while (!s.empty()) {
        long long temp = fr[s.top().second];
        fr[s.top().second] += f * (temp - 1) + f;
        f += temp;
        s.pop();
    }
    
    // for (int i = 0; i < n; i++)
    //     cout << fr[i] << " ";
    // cout << endl;
    
    unsigned long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += (unsigned long long)fr[i] * a[i];
    printf("%llu\n", ans);
    return 0;
}
