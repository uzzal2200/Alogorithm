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
    return a.w < b.w;
}
const int N=1e5+5;
int parent[N];
int pz[N];
void dsu_set(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        pz[i]=1;
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
      if(pz[leaderA] > pz[leaderB])
      {
        parent[leaderB]=leaderA;
        pz[leaderA] += pz[leaderB];
     }
     else
     {
         parent[leaderA]=leaderB;
        pz[leaderB] += pz[leaderA];
     }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    dsu_set(n);
    vector<Edge> v;
    vector<Edge>ans;
    while(m--)
    {
        int a,b;
        long long w;
        cin>>a>>b>>w;
    v.push_back(Edge(a,b,w));
    }
    sort(v.begin(),v.end(),cmp);

    for(Edge val: v)
    {
        int a=val.a;
        int b=val.b;
       long long  w=val.w;
        int leaderA=dsu_find(a);
        int leaderB=dsu_find(b);
        if(leaderA == leaderB) continue;
        ans.push_back(val);
        dsu_union(a,b);
    }
    long long sum=0;
    for(Edge val: ans)
    {
        sum += (long long )(val.w);
    }
    cout<<sum<<endl;
    return 0;
}
