#include<bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
int add_self(int &a,int b)
{
    a+=b;
    if(a>=mod)
    {
        a-=mod;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<bool>>can(n,vector<bool>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<nl;j++)
        {
            scanf("%d",&can[i][j]);
        }
    }
    vector<int>dp(1<<n);
    dp[0]=1;
    for(int mask=0;mask<(1<<n)-1;mask++)
    {
        int a=__builtin_popcount(mask);
        for(int b=0;b<n;b++)
        {
            if(can[a][b]&&!(mask & (1<<b)))
            {
                int m2=mask ^ (1<<b);
                add_self(dp[m2],dp[mask]);
            }
        }
    }
    printf("%d\n",dp[(1<<n)-1]);
}

