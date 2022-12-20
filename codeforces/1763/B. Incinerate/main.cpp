#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define allof(x) x,x+(sizeof(x)/sizeof(x[0]))
#define tolower(x) transform(x.begin(),x.end(),x.begin(),::tolower)
#define toupper(x) transform(x.begin(),x.end(),x.begin(),::toupper)
#define endl "\n"

using namespace std;
using namespace __gnu_pbds;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


#define oset(dt) tree< dt ,  null_type ,  less<dt> ,  rb_tree_tag ,  tree_order_statistics_node_update >
// find_by_order(k), order_of_key(k)

void file(string s = "me"){
    #ifdef DEBUG 
        freopen("me.in", "r", stdin);
        freopen("me.out", "w", stdout);
    #else
        //freopen((s+".in").c_str(), "r", stdin);
        //freopen((s+".out").c_str(), "w", stdout);
    #endif 
}
#ifdef DEBUG
    #include <M:\Programming\codeforces\cpp\File\debug.hpp>
#else
    #define debug(...)
    #define debug_itr(...)
    #define debug_bits(...)
#endif
string bin(ll num){
    return (bitset<65>(num).to_string());
}
bool cmp(const pair<ll,ll> &a,
            const pair<ll,ll> &b){
    return a.second < b.second;
}

void solve(){ 
    ll n,k;
    cin >> n >> k;
    ll h[n]{}, p[n]{};
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    for(int i=0; i<n; i++){
        pq.push({p[i],h[i]});
    }
    ll cur = k;
    while(k>0  && pq.size()){
        while(pq.size() && (pq.top().second <= cur))
            pq.pop();
        k-= pq.top().first;
        cur += k;
    }
    cout << (pq.size() ? "NO" : "YES" ) << endl;

}



signed main(){
    startTime = clock();
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    file();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    #ifdef DEBUG
        cout << "\nrunning time: " << getCurrentTime() << endl;
    #endif
    
}