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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s, r;
        cin >> s;
        vector<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' || s[i] == ']') {
                char op = s[i] == ')' ? '(' : '[';
                bool ok = false;
                while (st.size()) {
                    char cl = st.back() == '(' ? ')' : ']';
                    if (st.back() == op) {
                        ok = true;
                        st.pop_back();
                        break;
                    } else {
                        r += cl;
                        st.pop_back();
                    }
                }

                if (!ok) r += op;
            } else {
                st.push_back(s[i]);
            }

            r += s[i]; // guarantee the subsequence
        }

        while (st.size()) {
            char cl = st.back() == '(' ? ')' : ']';
            r += cl;
            st.pop_back();
        }

        cout << r << endl;
        if (t) cout << endl;
    }

    return 0;
}
