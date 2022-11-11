#include <bits/stdc++.h>

using namespace std;


#define endl '\n'
#define yes cout<<"yes\n";
#define Yes cout<<"Yes\n";
#define YES cout<<"YES\n";
#define no cout<<"no\n";
#define No cout<<"No\n";
#define NO cout<<"NO\n";
#define loop(n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define pi (3.141592653589)
#define rep(i,n) for(int i=0;i<n;i++)
#define arrn ll n;cin>>n;ll arr[n];loop(n)cin>>arr[i];
#define pll pair<ll,ll>
#define vll vector<ll>
#define sz(x) x.size()

typedef long long ll;

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}



struct point
{
    int x,y,z;
};




bool IsPrime(ll x)
{
    if(x<2)
        return false;
    if(x==2)
        return true;
    if(x%2==0)
        return false;
    for(int i=3;x<=i*i;i+=2)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

inline ll sumton(ll n){return n*(n+1)/2;}




ll sumofdigits(ll x)
{
    ll sum=0;
    while(x>0)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}

ll mod = 10e9 + 7;


void solve()
{

    ll n,m;
    cin>>n>>m;
    ll arr[n];
    loop(n)cin>>arr[i];

    pll query[m];

    loop(m)
    {
        ll k;
        cin>>k;
        query[i]= {k, i};
    }

    printf("---------\n");
    printf("%p\t%p\n", &n, &m);
    printf("%p\t%p\n", arr, query);
    printf("%p\t%p\n", arr, arr + 1);
    return;

    sort(query , query +m);


    ll ans[m];

    ll now=0,sum=0;
    for(int i=0;i<m;i++)
    {
        while(query[i].first >= arr[now] && now != n)
        {
            sum+=arr[now];
            now++;
        }
        ans[query[i].second]=sum;
    }

    loop(m)
    cout << ans[i] <<' ';
    cout << endl;






}

int main()
{
    ll t=1;

    cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}

