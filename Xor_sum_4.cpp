#include<bits/stdc++.h>
using namespace std;
const long int MOD = 1e9+7;
int main()
{
    long long int n;
    cin>>n;
    long long int a[n],ans=0;
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int k=0;
    for(long long int i=0;i<64;i++)
    {
        k=0;
        for(long long int j=0;j<n;j++)
        {
            if(a[j]&(1LL<<i))
                k++;
        }
        ans=((ans)%MOD+((1LL<<i)*((k*(n-k))%MOD))%MOD)%MOD;

    }
    cout<<ans<<endl;
    return 0;
}