#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int n = S.length();
    vector<int> v;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        vector<int> fr(26);
        fr[S[i] - 'a']++;

        int ii = -1;
        for (int j = (int) v.size() - 1; j >= 0; j--) {
            int &f = fr[S[v[j]] - 'a'];
            if (++f > 1) {
                ii = v[j];
                break;
            }
        }

        ans += (i - ii);
        if (T[S[i] - 'a'] == '1') v.push_back(i);
    }

    cout << ans << endl;
    return 0;
}

