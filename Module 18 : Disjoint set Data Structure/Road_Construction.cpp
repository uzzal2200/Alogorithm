#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
int parent_size[N];
void dsu_set(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        parent_size[i]=1;
    }
}
int dsu_find(int node)
{
while(parent[node] != -1)
{
    node=parent[node];
}
return node;
}
int mx=0;
void dsu_union(int a,int b)
{
    int leaderA=dsu_find(a);
    int leaderB=dsu_find(b);
    if(leaderA != leaderB)
    {
        if(parent_size[leaderA] > parent_size[leaderB])
        {
            parent[leaderB]=leaderA;
            parent_size[leaderA]+=parent_size[leaderB];
            mx=max(mx,parent_size[leaderA]);
        }
        else
    {
        parent[leaderA]=leaderB;
        parent_size[leaderB]+=parent_size[leaderA];
        mx=max(mx,parent_size[leaderB]);
    }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    int cmp=n;
    while(e--)
   {
    int a,b;
    cin>>a>>b;
    int leaderA=dsu_find(a);
    int leaderB=dsu_find(b);
    if(leaderA != leaderB)
    {
        cmp--;
        dsu_union(a,b);
       
    }
     cout<<cmp<<" "<<mx<<endl;
   }
    return 0;
}
