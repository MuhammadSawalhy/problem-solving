/*
author: tpbluesky
time: 2015年8月13日21:16:21
题目: 动态规划，dp[i][j]表示第i种物品的价格，那么dp[i][j] = min(dp[i-1][k] + 存储这个物品的代价)
初始化: dp[i][j] = (i+week[i].need)*week[i].price + j*storeprice + base;
有一个情况，当week[1].need == 0时，dp[1][0] = 0;
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <limits.h>
#include <queue>

#define inf 0x3f3f3f3f
#define eps 1e-8
using namespace std;
typedef long long ll;
const int maxn = 1005;
int dp[maxn][maxn];
struct node
{
    int price;
    int need;
}week[maxn];

int main()
{
    int n, base, kstore, cap;
    while(scanf("%d",&n) && n)
    {
        scanf("%d%d%d",&base,&kstore,&cap);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d",&week[i].price,&week[i].need);
        }
        for (int i = 0; i <= cap; ++i)
        {
            dp[1][i] = (i+week[1].need)*week[1].price + i*kstore + base;
            if(week[1].need == 0)
                dp[1][0] = 0;
        }
        int minx, miny;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j <= cap;++j)
            {
                minx = inf;
                for (int k = 0;k <= cap;++k)
                {
                    if(k - week[i].need <= j) //大于的话，这种情况是达不到的，因为已经有
                    {
                        //上星期的城去捡week[i].need正好是一个，
                        if (k - week[i].need == j)
                            miny = dp[i-1][k] + j*kstore;
                        else
                            miny = dp[i-1][k] + (j-k+week[i].need)*week[i].price + j*kstore + base;
                        minx = min(minx,miny);
                    }
                }
                dp[i][j] = minx;
            }
        }
        minx = inf;
        for (int i = 0; i <= cap;++i)
        {
            minx = min(dp[n][i],minx);
        }
        printf("%d\n",minx);
    }
    return 0;
}

