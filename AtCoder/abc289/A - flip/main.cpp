// ﷽
#include <iostream>

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

    string s;
    cin >> s;

    for (int i = 0; i < (int)s.size(); i++)
        s[i] = s[i] == '0' ? '1' : '0';

    cout << s << endl;

    return 0;
}
