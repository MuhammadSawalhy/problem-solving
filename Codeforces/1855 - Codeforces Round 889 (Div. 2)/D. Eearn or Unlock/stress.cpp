#pragma GCC optimize(3)
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N=200007;
const int INF=1e9;
const int mod=1e9+7;
const double pi=acos(-1);
mt19937_64 rng(time(NULL));
 
int n;
int a[N];
int sum[N];

bitset<200007> bs;
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin>>n;
  for (int i=1;i<=n;++i) cin>>a[i];
  for (int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
  bs[1]=1;
  int ans=0;
  for (int i=1;i<=n;++i){
    if (sum[i]<i) break;
    bs|=(bs<<a[i]);
    if (bs[i]) ans=max(ans,sum[i]-i+1), bs[i]=0;
  }
  for (int i=n+1;i<=2*n;++i){
    if (bs[i]) ans=max(ans,sum[n]-i+1), bs[i]=0;
  }
  cout<<ans<<endl;
}  
