#include<bits/stdc++.h>
using namespace std;
 
int n,k,r,s,p;
string t;
int rps(char d)
{
    if(d=='r') return p;
    else if(d=='p') return s;
    else return r; 
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>k;
    cin>>r>>s>>p;
    cin>>t;
    int dp[100011]={0};
    int res=0;
    for(int i=0;i<k;i++)
    {
        res+=rps(t[i]);
        dp[i]=res;
    }
    for(int i=k;i<t.size();i++)
    {
        if(t[i-k]==t[i])
        {
            dp[i]=max(dp[i-k],dp[i-1]);
            t[i]='0';
        }
        else{
            dp[i]=dp[i-1]+rps(t[i]);
        }
    }
    cout<<dp[n-1];
    return 0;
}