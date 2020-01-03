#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h,w;
    cin>>h>>w;
    int a[85][85],b[85][85];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>b[i][j];
        }
    }
    bool dp[h+1][w+1][6401];
    dp[0][1][0]=true;
    dp[1][0][0]=true;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            for(int k=0;k<6400;k++)
            {
                if(dp[i+1][j][k]||dp[i][j+1][k])
                {
                    int x=abs(k+a[i][j]-b[i][j]);
                    if(x<6400)
                    {
                        dp[i+1][j+1][x]=true;
                    }
                    x=abs(k+b[i][j]-a[i][j]);
                    if(x<6400)
                    {
                        dp[i+1][j+1][x]=true;
                    }

                }
            }
        }
    }

    int m=6400;
    for(int i=0;i<6400;i++)
    {
        m=min(m,dp[h][w][i]);
    }
    cout<<m<<endl;
    return 0;

}