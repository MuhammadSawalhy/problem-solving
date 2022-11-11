#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};	
//////////////////////

const int N = 10010;

#define EPS 1e-8

typedef pair<ll, ll> IndexValue;

struct IndexValueCompare{
    inline bool operator() (const IndexValue &one, const IndexValue &another) const {
        return one.second < another.second;
    }
};

vector<ll> LIS(const vector<ll> &sequence){
    vector<ll> parent(sequence.size());
    set<IndexValue, IndexValueCompare> s;
    for(int i = 0; i < sequence.size(); ++i){
        IndexValue iv(i, sequence[i]);
        if(i == 0){
            s.insert(iv);
            continue;
        }
        auto index = s.lower_bound(iv);
        if(index != s.end()){
            if(sequence[i] < sequence[index->first]){
                if(index != s.begin()) {
                    parent[i] = (--index)->first;
                    index++;
                }
                s.erase(index);
            }
        } else{
            parent[i] = s.rbegin()->first;
        }
        s.insert(iv);
    }
    vector<ll> result(s.size());
    int index = s.rbegin()->first;
    for(auto iter = s.rbegin(); iter != s.rend(); index = parent[index], ++iter){
        result[distance(iter, s.rend()) - 1] = index;
    }
    return result;
}

int n;
vi v;

int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        v.clear();
        for(int i=0;i<n;++i)
        {
            ll x;
            scanf("%lld",&x);
            v.pb(x);
        }
        vi aux = LIS(v);
        if( aux.size() == 1 ) 
        {
            printf("0\n");
            continue;
        }
        
        int len = aux.size();
        ll p1 = v[aux[0]];
        ll p2 = -LINF;
        int ult = aux[len-2];
        for(int i=ult+1;i<n;++i)
        {
            if( v[i] > v[ult] ) p2 = max( p2, v[i] );
        }
        printf("%lld\n",p2-p1);
        
    }
    return 0;
}
