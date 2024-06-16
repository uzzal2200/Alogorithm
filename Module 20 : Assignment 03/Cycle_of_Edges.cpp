#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
int parent_level[N];
void dsu_set(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i] = -1;
        parent_level[i]=0;

    }
}
int dsu_find(int node)
{
    while(parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a,int b)
{
    int leaderA=dsu_find(a);
    int leaderB=dsu_find(b);
    if(leaderA != leaderB)
    {
        if(parent_level[leaderA] > parent_level[leaderB])
        {
            parent[leaderB]=leaderA;
        }
        else if(parent_level[leaderB] > parent_level[leaderA])
        {
            parent[leaderA]=leaderB;
        }
        else
        {
            parent[leaderB]=leaderA;
            parent_level[leaderA]++;
        }
        
    }
}
int main()
{
    int n,e;
   // long long e;
    cin>>n>>e;
    dsu_set(n);
     int cnt=0;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
    int leaderA=dsu_find(a);
    int leaderB=dsu_find(b);
   
    if(leaderA == leaderB)
    {
       
       cnt++;
       
       
    }
      else
        dsu_union(a,b);
      
    }
    cout<<cnt<<endl;
    return 0;
}
