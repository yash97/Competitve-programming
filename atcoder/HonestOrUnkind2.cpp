#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a[20],x[20][20],y[20][20];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=a[i];j++)
        {
            cin>>x[i][j]>>y[i][j];
        }
    }
    int ans=0;
    bool flag=true;
    for(int bits=1;bits<(1<<n);bits++)
    {
        flag=true;
        for(int i=1;i<=n;i++)
        {
            if(!(bits&(1<<(i-1))))continue;
            for(int j=1;j<=a[i];j++)
            {
                if(((bits>>x[i][j]-1)&1)^y[i][j])flag=false;
            }
        }
        if(flag)ans=max(ans,__builtin_popcount(bits));
    }
    cout<<ans;
    return 0;
}