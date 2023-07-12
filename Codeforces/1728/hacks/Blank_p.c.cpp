
#include<bits/stdc++.h>

using namespace std;

/************************macros***************************************************/

#define int long long
#define all(v)        ((v).begin()), ((v).end())
#define allr(v)        ((v).rbegin()), ((v).rend())
#define sz(v)        ((int)((v).size()))
#define clr(v, d)      memset(v, d, sizeof(v))
#define rep(i, v)    for(int i=0;i<sz(v);++i)
#define lp(i, n)    for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)  for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)  for(int i=(j);i>=(int)(n);--i)
#define ceils(x, y) (x + y - 1) / y

//for pairs
#define pii pair<int, int>
#define vii vector<pii>

const double EPS = (1e-7);

int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int fix(int a, int n) {
    return (a % n + n) % n;
}

#define pb          push_back
#define MP          make_pair
#define P(x)        cout<<#x<<" = { "<<x<<" }\n"
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;

string s;


int len(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int solve() {
    int n;
    cin >> n;

    multiset<int> a, b;
    lp(i, n) {
        int x;
        cin >> x;
        a.insert(x);
    }

    lp(i, n) {
        int x;
        cin >> x;
        b.insert(x);
    }

    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    int cnt = 0;
    while (sz(a) > 0) {
        if (*a.rbegin() < *b.rbegin())
            swap(a, b);
        auto x = *a.rbegin();
        if (b.find(x) != b.end()) {
            a.erase(a.find(x));
            b.erase(b.find(x));
        } else {
            a.erase(a.find(x));
            a.insert(len(x));
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}