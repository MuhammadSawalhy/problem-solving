//这回只花了45min就打完了。
#include "/home/ms/myp/problem-solving/debug.hpp"
#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(),(x).end()

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--) {
		int n,r;
		cin>>n;
		vector<int> a(n);
		for (int &x:a) cin>>x,x=__builtin_ffs(x)-1;
		r=*min_element(all(a));
		std::cerr << "r, " << std::endl;
		for (int x:a) r+=(x>0);
		cout<<r<<'\n';
	}
}
