#include <bits/stdc++.h>

using namespace std;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
template < typename T = int > using Pair = pair < T, T >;
vector < string > RET = {"NO", "YES"};

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}

template < typename T = int, int Base = 0 > struct MO {

    struct query {

        int l, r, query_idx, block_idx;

        query(int L = 0, int R = 0, int Query_idx = 0){
            l = L - !Base, r = R - !Base, query_idx = Query_idx;
        }

        bool operator < (const query& q) const {
            return (block_idx < q.block_idx) || (block_idx == q.block_idx && r < q.r);
        }

    };

    T curr_l, curr_r, ans, n, m, Sqrt_N;
    vector < T > answers, nums, freq, nCr;
    vector < query > queries;

    MO(int N = 0, int M = 0){
        curr_l = 1, curr_r = 0, ans = 0, n = N, m = M, Sqrt_N = n / sqrt(m) + 1;
        queries = vector < query > (m);
        answers = vector < T > (m);
        nums = nCr = vector < T > (n + 5);
        freq = vector < T > (2e5 + 5);
    }

    void set_block_id(){
        for(int i = 0; i < m; i++)
            queries[i].block_idx = queries[i].l / Sqrt_N;
    }
    
    T nCr_Freq(T f){
        if(f < 3) return 0;
        return f * (f - 1) * (f - 2) / 6;
    }

    void Get_Data(vector < T > &v){
        // get the array and set the queries
        nums = v;

        for(int i = 0, l, r; i < m && cin >> l >> r; i++)
            queries[i] = query(l, r, i);

        for(int i = 0; i <= n; i++)
            nCr[i] = nCr_Freq(i);        

        // set the block id for each query
        set_block_id();
    }

    // add the idx to the current range
    void add(int idx){
        cerr << "adding " << idx << endl;
        ans -= nCr[freq[nums[idx]]];
        ans += nCr[++freq[nums[idx]]];   
    }

    // remove the idx from the current range
    void remove(int idx){
        cerr << "removing " << idx << endl;
        ans -= nCr[freq[nums[idx]]];
        ans += nCr[--freq[nums[idx]]];
    }

    void set_range(query& q){
        // add the new range and remove the old range
        while(curr_l > q.l) add(--curr_l);
        while(curr_r < q.r) add(++curr_r);
        while(curr_l < q.l) remove(curr_l++);
        while(curr_r > q.r) remove(curr_r--);
    }

    void Process(){
        
        sort(all(queries));

        // to start with the first query
        curr_l = queries[0].l, curr_r = queries[0].l - 1;

        for(int i = 0; i < m; i++){
            set_range(queries[i]);
            answers[queries[i].query_idx] = ans;
        }
    }

    void Print_queries_answers(){
        for(int i = 0; i < m; i++)
            cout << answers[i] << '\n';
    }

    vector < T > Get_answers(){
        return answers;
    }

};

void Solve(){
    int n, q;
    cin >> n >> q;
    vector < ll > a(n);
    cin >> a;
    MO < ll > mo(n, q);
    mo.Get_Data(a);
    mo.Process();
    mo.Print_queries_answers();
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    // cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
