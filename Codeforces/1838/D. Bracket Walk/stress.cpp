// Geothermal: https://codeforces.com/contest/1838/submission/208459416
#include "bits/stdc++.h"
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T>
using pq = priority_queue<T>;
template<class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) -1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a) -1; i >= 0; i--)
#define trav(a, x) for (auto &a: x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int) (x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << '}';
}
template<typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template<typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifdef DEBUG
#define dbg(x...)                                                             \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
    _print(x);                                                                \
    cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

int N, Q;
string S;
vi qs;
vector<int> ans;

const ll identity = MOD;
const ll SZ = 131072 * 2;

ll sum[2 * SZ], lazy[2 * SZ];

ll combine(ll A, ll B) {
    return min(A, B);
}

ll combineUpd(ll A, ll B) {
    return A + B;
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2 * index] = combineUpd(lazy[2 * index], lazy[index]), lazy[2 * index + 1] = combineUpd(lazy[2 * index + 1], lazy[index]);
    lazy[index] = 0;
}

void pull(int index) {
    sum[index] = combine(sum[2 * index], sum[2 * index + 1]);
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ - 1) {
    push(index, L, R);
    if (lo > R || L > hi) return identity;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L + R) / 2;
    return combine(query(lo, hi, 2 * index, L, M), query(lo, hi, 2 * index + 1, M + 1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ - 1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L + R) / 2;
    update(lo, hi, increase, 2 * index, L, M);
    update(lo, hi, increase, 2 * index + 1, M + 1, R);
    pull(index);
}
void go() {
    F0R(i, 2 * SZ) {
        sum[i] = 0;
        lazy[i] = 0;
    }
    F0R(i, N) {
        update(i, N - 1, (S[i] == '(' ? 1 : -1));
    }
    set<int> dubs;
    dubs.ins(N - 1);
    F0R(i, N - 1) {
        if (S[i] == '(' && S[i + 1] == '(') dubs.ins(i);
    }
    string T = S;
    F0R(i, Q) {
        int a = qs[i];
        if (T[a] == '(') {
            T[a] = ')';
            if (a < N - 1 && T[a + 1] == '(') dubs.erase(a);
            if (a && T[a - 1] == '(') dubs.erase(a - 1);
            update(a, N - 1, -2);
        } else {
            T[a] = '(';
            if (a < N - 1 && T[a + 1] == '(') dubs.ins(a);
            if (a && T[a - 1] == '(') dubs.ins(a - 1);
            update(a, N - 1, 2);
        }
        ans.pb(query(0, *dubs.begin()) >= 0);
    }
}

void solve() {
    cin >> N >> Q;
    cin >> S;
    if (N % 2) {
        while (Q--) {
            int X;
            cin >> X;
            cout << "NO" << nl;
        }
        return;
    }
    F0R(i, Q) {
        int X;
        cin >> X;
        qs.pb(X - 1);
    }
    go();
    vector<int> ans1 = ans;
    ans.clear();
    reverse(all(S));
    trav(a, S) {
        a = '(' + ')' - a;
    }
    trav(a, qs) {
        a = N - 1 - a;
    }
    go();
    F0R(i, Q) {
        cout << (ans1[i] && ans[i] ? "YES" : "NO") << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    //    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
