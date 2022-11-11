#include<bits/stdc++.h>
using namespace std;
bool chk(vector<int> num)
{
    //for(auto it:num)cout<<it<<" ";
    cout<<endl;
    if(num.empty())return true;
    if(num[0]+1<=num.size())
    {
        vector<int> temp(num.begin()+num[0]+1,num.end());
        if(chk(temp))return true;
    }
    for(int i=1;i<num.size();i++)
    {
        if(i==num[i])
        {
            vector<int> send(num.begin()+i+1,num.end());
            if(chk(send))return true;
        }
    }
    return false;
}
int main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int xxx;
    cin>>xxx;
    while(xxx--)
    {
        int n;
        cin>>n;
        vector<int> num;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            num.push_back(a);
        }
        if(chk(num)) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
