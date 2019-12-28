#include<bits/stdc++.h>

using namespace std;

const int nax=1e5+5;
vector<int>edges[nax];
const int mod=1e9+7;
int mul(int a,int b)
    return a * b % mod;


pair<int,int> dfs(int a,int parent)
{
    int all_white=1;
    int smth_black=0;
    for(int b:edges[a])
    {
        if(b!=parent)
        {   //p.first means the child b is black

            pair<int,int>p=dfs(b,a);
            int temp_white=all_white;
            all_white=mul(all_white,p.second);
            smth_black=mul(temp_white,p.first)+ mul(smth_black,p.first+p.second);
        }
    }
    return make_pair(all_white,(all_white+smth_black)%mod);
}


int main()
{
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    pair<int,int>p=dfs(1,-1);
    cout<<p.first+p.second<<endl;

}