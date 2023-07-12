#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>
//struct student {
//	string name;
//	int gA;
//	int gM;
//	int gS;
//	int gE;
//	int sum = gA + gS + gM + gE;
//};
//bool sortt(student e,student e1)
//{
//	if (e.sum != e1.sum)
//		return e.sum > e1.sum;
//	else
//		return e.name < e1.name;
//}
int main()
{
	int n, m, q,value;
	cin >> n >> m >> q;
	typedef unsigned long long ull;
	typedef vector<ull> vull;
	vector<vull>output = vector<vull>(n + 1, vull(m + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> output[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			output[i][j] += output[i][j - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			output[i][j] += output[i-1][j];
		}
	}
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ull ans = output[x2][y2];
		ans -= output[x1 - 1][y2];
		ans -= output[x2][y1 - 1];
		ans += output[x1 - 1][y1 - 1];
		cout << ans << endl;
	}
	return 0;
  }

