/*
 * I used HBD method to solve this problem, which means you can't hack it. GLHF.
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl '\n'

#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define lp(n) for(ll i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define pi (3.141592653589)
#define rep(i, n) for(int i=0;i<n;i++)
#define arrn ll n;cin>>n;ll arr[n];lp(n)cin>>arr[i];
#define pll pair<ll,ll>
#define vll vector<ll>
#define sz(x) x.size()
#define pb(x) push_back(x)
#define ff first
#define ss second
#define feach(p, stl) for(auto &p : stl)
//#define int long long


void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


struct point {
    int x, y, z;
};


bool IsPrime(ll x) {
    if (x < 2)
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0)
            return false;
    }
    return true;
}

inline ll ntosum(ll n) { return n * (n + 1) / 2; }


ll sumofdigits(ll x) {
    ll sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}




double sumton(double s) {
    return (-(1.0 - sqrtl(1.0 + (8.0 * s))) / 2.0);
}

int modpow(int x, int n, int m) {
    if (n == 0) return 1 % m;
    long long u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}


class SegmentTree { // OOP style
private:
    ll n; // n = (int)A.size()
    vll A, st, lazy; // the arrays
    ll l(ll p) { return p<<1; } // go to left child
    ll r(ll p) { return (p<<1)+1; } // go to right child
    ll conquer(ll a, ll b) {
        if (a == -1) return b; // corner case
        if (b == -1) return a;
        return a+b; // RMQ
    }
    void build(ll p, ll L, ll R) { // O(n)
        if (L == R)
            st[p] = A[L]; // base case
        else {
            int m = (L+R)/2;
            build(l(p), L , m);
            build(r(p), m+1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }
    void propagate(ll p, ll L, ll R) {
        if (lazy[p] != -1) { // has a lazy flag
            st[p] = lazy[p]; // [L..R] has same value
            if (L != R) // not a leaf
                lazy[l(p)] = lazy[r(p)] = lazy[p]; // propagate downwards
            else // L == R, a single index
                A[L] = lazy[p]; // time to update this
            lazy[p] = -1; // erase lazy flag
        }
    }
    ll RMQ(ll p, ll L, ll R, ll i, ll j) { // O(log n)
        propagate(p, L, R); // lazy propagation
        if (i > j) return -1; // infeasible
        if ((L >= i) && (R <= j)) return st[p]; // found the segment
        ll m = (L+R)/2;
        return conquer(RMQ(l(p), L , m, i , min(m, j)),
                       RMQ(r(p), m+1, R, max(i, m+1), j ));
    }
    void update(ll p, ll L, ll R, ll i, ll j, ll val) { // O(log n)
        propagate(p, L, R); // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) { // found the segment
            lazy[p] = val; // update this
            propagate(p, L, R); // lazy propagation
        }
        else {
            ll m = (L+R)/2;
            update(l(p), L , m, i , min(m, j), val);
            update(r(p), m+1, R, max(i, m+1), j , val);
            ll lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            ll rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];


            st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
        }
    }
public:
    SegmentTree(ll sz) : n(sz), st(4*n), lazy(4*n, -1) {}
    SegmentTree(const vll &initialA) : SegmentTree((ll)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }
    void update(int i, ll j, ll val) { update(1, 0, n-1, i, j, val); }
    ll RMQ(ll i, ll j) { return RMQ(1, 0, n-1, i, j); }
};


void pre()
{

    //Precalculate before testcases here!

}

vector<ll> factor(ll n) {
    vector<ll> ret;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n > 1) { ret.push_back(n); }
    return ret;
}

ll mod = 1e9 +7;


void solve() {

    ll n,q;
    cin>>n>>q;
    ll arr[n];
    lp(n)cin>>arr[i];

    sort(arr,arr+n);

    ll b[n];
    ll k;
    while(q--)
    {
        lp(n)b[i]=arr[i];
        cin>>k;

        ll minus = 0;
        if(k>n)
        {
            minus = k-n + (k-n)%2;
        }


        ll z=k;
        for(int i=0;z>minus;i++,z--)
        {
            b[i]+=z;
        }

        ll ans=b[0];
        lp(n)ans=min(ans,b[i]);

        ll sum=0;
        lp(n)sum+=b[i];
        sum-=(minus/2);


        cout << min(ans, sum/n)<<' ';
    }


}

int32_t main() {

    pre();
    fast();

    int test_cases=1;
    //cin>>test_cases;
    for (int i = 1; i <= test_cases; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}
