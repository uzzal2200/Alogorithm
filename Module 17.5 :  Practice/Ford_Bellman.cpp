#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e2+5;
const int INF=1e9+5;
vector<pair<pii,int> > v;
int dis[N];
int n,e;
void bellmenford(int src)
{
    for(int i=1;i<=n;i++)
    {
     dis[i]=INF;
    }
    dis[src]=0;
   for(int i=1;i<=n;i++)
   {
     for(auto edge: v)
    {
        int a=edge.first.first;
        int b=edge.first.second;
        int w=edge.second;
        if(dis[a] < INF && dis[b] > dis[a] + w)
        {
            dis[b]=dis[a]+w;
        }
    }
   }
}
int main()
{
    cin>>n>>e;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v.push_back({{a,b},w});
    }
    bellmenford(1);
    for(int i=1;i<=n;i++)
    {
        if(dis[i] == INF) cout<<"30000";
      else  cout<<dis[i]<<" ";
    }
    return 0;
}