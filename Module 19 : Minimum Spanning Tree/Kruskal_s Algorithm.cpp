#include<bits/stdc++.h>
using namespace std;
class Edge
{
 public:
 int a,b,w;
 Edge(int a,int b,int w)
 {
    this->a=a;
    this->b=b;
    this->w=w;
 }
};
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
const int N=1e5+5;
int parent[N];
int parent_size[N];
void dsu_set(int n)
{
  for(int i=1;i<=n;i++)
  {
      parent[i]=-1;
      parent_size[i]=-1;
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
        }
        else
        {
            parent[leaderA]=leaderB;
            parent_size[leaderB]+=parent_size[leaderA];
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    vector<Edge> v;
    vector<Edge>ans;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v.push_back(Edge(a,b,w));
    }
    sort(v.begin(),v.end(),cmp);
    // for(Edge val: v)
    // {
    //  cout<<val.a<<" "<<val.b<<" "<<val.w<<endl;
    // }
    for(Edge val: v)
    {
        int a=val.a;
        int b=val.b;
        int w=val.w;
         int leaderA=dsu_find(a);
         int leaderB=dsu_find(b);
         if(leaderA == leaderB) continue;
         ans.push_back(val);
         dsu_union(a,b);
    }
    for(Edge val: ans)
    {
        cout<<val.a<<" "<<val.b<<" "<<val.w<<endl;
    }
    return 0;
}
