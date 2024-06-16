#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e5+5;
const long long INF=1e18+5;
vector<pair<pii,long long> > v;
long long dis[N];
int n,e;
bool bellmenford(int src)
{
 for(int i=1;i<=n;i++)
 {
    dis[i]=INF;
 }
  dis[src]=0;
  bool flag = false;
  for(int i=1;i<=n;i++)
  {
    for(auto child: v)
    {
      int a=child.first.first;
      int b=child.first.second;
      int w=child.second;
      if( dis[a] != INF && dis[b] > dis[a] + w)
      {
        dis[b]=dis[a] + w;
       if(i == n)
       {
        flag = true;
       }
      }
    }
  }
  return flag;
}

int main()
{
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        long long w;
        cin>>a>>b>>w;
       v.push_back({{a,b},w});
    }
    int src;
    cin>>src;
    bool f=bellmenford(src);
    if(f) 
    {
        cout<<"Negative Cycle Detected"<<endl;
        return 0;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int d;
        cin>>d;
        if(dis[d] == INF) cout<<"Not Possible"<<endl;
        else cout<<dis[d]<<endl;
    }
    return 0;
}
