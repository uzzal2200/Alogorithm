#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<pair<int,int> > adj[N];
int dis[N];
int n,e;
void dijkstra(int src)
{
    for(int i=1;i<=n;i++)
    {
        dis[i] = INT_MAX;
    }
  queue<int> q;
  q.push(src);
  dis[src]=0;
  while(!q.empty())
  {
    int parent=q.front();
    q.pop();
    for(pair<int,int> child: adj[parent])
    {
        int childNode=child.first;
        int childCost=child.second;
        if(dis[childNode] > dis[parent] + childCost)
        {
            dis[childNode] = dis[parent] + childCost;
            q.push(childNode);
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
       adj[a].push_back({b,w});
      adj[b].push_back({a,w});
    }
    
    dijkstra(1); // complexity O(N*E)
    for(int i=1;i<=n;i++)
    {
        cout<<"Node "<< i <<": "<<dis[i]<<endl;
    }
   return 0;
}
