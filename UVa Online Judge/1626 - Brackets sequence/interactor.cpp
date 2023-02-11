/*
	Author: Abdulla Ashraf
	Idea:
        -use a dp check using left and right pointers as paramters 
        -stop when left == right and return 1 or left > right and return 0
        -every step try to split the string at each index and try to match the 2 outer brackets
        -make a recursion trace function to know one of the best ways
*/


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-9;

const int N = (1 << 15);
const ll OO = 2ll * 1e8;

string x;
int mem[105][105];

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

string genx() {
    int n;
    n = gen();
    string x;
    while (n--)
        x += "[()]"[gen(0, 3)];
    return x;
}

int go(int l,int r)
{
    if(l > r)
        return 0;
    if(l == r)
        return 1;
    int &ret = mem[l][r];
    if(ret != -1)
        return ret;
    ret = OO;
    if(x[l] == '(' && x[r] == ')' || x[l] == '[' && x[r] == ']')
        ret = min(ret,go(l+1,r-1));
    for(int i=l; i<r; i++)
        ret = min(ret,go(l,i)+go(i+1,r));
    return ret;
}

vector<int> ad;

void go2(int l,int r)
{
    if(l > r)
        return;
    if(l == r)
    {
        ad.pb(l);
        return;
    }

    for(int i=l; i<r; i++)
        if(mem[l][r] == go(l,i)+go(i+1,r))
        {
            go2(l,i);
            go2(i+1,r);
            return;
        }
    go2(l+1,r-1);
}

int main(int argc, char *argv[])
{
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
    int T = 1;
    cout << T << endl;

    while(T--)
    {
        memset(mem,-1,sizeof mem);
        ad.clear();
        x = genx();
        cout << x << endl;
        go(0,x.size()-1);
        go2(0,x.size()-1);
        sort(ad.begin(),ad.end());
        int r = 0;
        string res;
        for(int i=0; i<x.size(); i++)
        {
            if(r < ad.size() && ad[r] == i)
            {
                r++;
                if(x[i] == ')' || x[i] == '(')
                    res += "()";
                else
                    res += "[]";
            }
            else
                res += x[i];
        }
        string mainres;
        cin >> mainres;
        cout << res << endl;
        assert(mainres.size() == res.size());
    }

    return 0;
}

