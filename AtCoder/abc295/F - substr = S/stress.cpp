#include<bits/stdc++.h>
#include <unordered_map>
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
#define _USE_MATH_DEFINES
# define M_PI           3.14159265358979323846  /* pi */
#define ll long long
#define ull unsigned long long
#define ld long double
#define vbe(v) ((v).begin()), ((v).end())
#define sz(v)     ((int)((v).size()))
#define prec(x)    cout<< fixed<< setprecision(x)
#define clr(v, d)   memset(v, d, sizeof(v))
#define rep(i, v)   for(int i=0;i<sz(v);++i)
#define lp(i, n)    for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)  for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)  for(int i=(j);i>=(int)(n);--i)
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define cntOnes(x) __builtin_popcount(x)
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cin.tie(0);
#define INFLL 1e18
#define INF 1e9
#define MOD 1000000007
#define MOD1 998244353
#define MAXN 200005
#define EPS 1e-6


ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }

ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

ll fastpow(ll b, ll p) {
    if (!p) return 1;
    ll ret = fastpow(b, p >> 1);
    ret *= ret;
    if (p & 1) ret *= b;
    return ret;
}

string str;
string num;
//12
//
const int N = 17;
ll dp[N][N][3][3][3];

ll goDP(int idxStr = 0, int idxI = 0, int state = 0, int f = 0, int nonZero = 0) {
    if (idxI == num.length())return idxStr == str.length();

    ll &ret = dp[idxStr][idxI][state][f][nonZero];
    if (~ret)return ret;
    ret = 0;
    if (state == 0)
        ret += goDP(idxStr, idxI, state + 1, f, nonZero);
    else if (state == 1 && idxStr == str.length()) {
        return ret = goDP(idxStr, idxI, 2, f, nonZero);
    }
    int sts = 0;
    int d = num[idxI] - '0';
    int end = 9;
    if (!f)
        end = d;
    for (int i = sts; i <= end; i++) {
        int newF = (f || (i < d));
        int newNonZ = nonZero || (i != 0);
        if (state == 0 || state == 2) {
            ret += goDP(idxStr, idxI + 1, state, newF, newNonZ);
        }
        if (state == 1) {
            if (str[idxStr] - '0' == i || idxStr == str.length()) {
                if (i == 0 && !nonZero) { ;
                } else {
                    ret += goDP(min(idxStr + 1, (int) str.length()), idxI + 1, state, newF, newNonZ);
                }
            }
        }
    }
    return ret;
}

ll slv(ll n) {
    // i from 0 to num
    // sum+=f(i)
    clr(dp, -1);
    num = to_string(n);
    return goDP();
}

void solve(int tst) {
    cin >> str;
    ll l, r;
    cin >> l >> r;
    ll ans = slv(r) - slv(l - 1);
    cout << ans;
}

int main() {
    FASTIO;
    //freopen("library.in", "r", stdin);
    int t = 1;
    cin >> t;
    lp(i, t) {
        solve(i + 1);
        cout << "\n";
    }
}
