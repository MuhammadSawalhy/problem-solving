#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i64 long long
#define endl '\n'
#define Endl '\n'
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define loop(n)          for(int i = 0; i < (n); i++)
const long long inf = (long long) 1e18;
#define fast    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N = 2e5 + 5;
ll mod = 1e9 + 7;
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
// bitwise functions ************************
#define pop_cnt(x) (__builtin_popcountll(x)) //num of ones int bits
#define LSB(x) (__builtin_ffsll(x) - 1)  \
        // int lowbit(int x){return x&(-x);}

#define MSB(x) (64 - __builtin_clzll(x) - 1)

//******************************************
template<class t>
void print(t printed) { cout << printed << endl; }
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
}
//#ifndef ONLINE_JUDGE
//#include <C:\Users\AhMeD\CLionProjects\b/debug.hpp>
//#else
//#define debug(...)
//    #define debug_itr(...)
//    #define debug_bits(...)
//#endif
/**************** Solution start from here ***********************/

struct floors {
        int ceilling;
        ll right ;
        ll left;

};
int main() {
    // file();
    fast
   int tc = 1;
    // cin >> tc;
    while (tc--) {
        string s;
        cin>>s;
        int n;
        cin>>n;

        int m=(int) s.size()+1;
        vector<floors>prfix(m);

        prfix[0]={0 , 0 , 0};
        for (int i = 1; i <m ; ++i) {
            if (s[i-1]=='_') {
                prfix[i] = prfix[i - 1];
                prfix[i].ceilling+=1;
            }

           else if (s[i-1]=='/') {
                prfix[i] = prfix[i - 1];
                prfix[i].right+=1;
            }
            else if (s[i-1]=='\\') {
                prfix[i] = prfix[i - 1];
                prfix[i].left+=1;

            }

        }


        while (n--){
            int l , r;
            cin>>l>>r;
            floors temp;
            temp.ceilling=prfix[r].ceilling-prfix[l-1].ceilling;
            temp.right=prfix[r].right-prfix[l-1].right;
            temp.left=prfix[r].left-prfix[l-1].left;


            // n^2+ n - 2x=0
            // n^2+n-2*temp.right;

            int delta1 = 1-4*(-2*temp.right);
            int delta2 = 1-4*(-2*temp.left);
            int delta3 = 1-4*(-2*temp.ceilling);

            int x1 , x2 , x3;

            x1= (-1 + sqrt(delta1)) / 2;
            x2= (-1 + sqrt(delta2)) / 2;
            x3= (-1 + sqrt(delta3)) / 2 + 1;
            
            cout << min({ x1, x2, x3 }) << endl;
        }

    }
    }




