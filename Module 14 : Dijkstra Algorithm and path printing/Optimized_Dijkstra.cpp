#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e3+5;
vector<pii> adj[N];
int dis[N];
bool visited[N];
int n, e;
void dijkstra(int src)
{
    for(int i=1;i<=n;i++)
    {
        dis[i] = INT_MAX;
    }
      priority_queue<pii,vector<pii>,greater<pii> > pq;
     pq.push({0,src});
     dis[src] =0;
     while(!pq.empty())
     {
        pii parent = pq.top();
        pq.pop();
        int parentnode=parent.second;
        if(visited[parentnode] == true) continue;
        visited[parentnode] = true;
        int parentcost=parent.first;
        for( pii child: adj[parentnode])
        {
            int childnode=child.first;
            int childcost=child.second;
            if(dis[childnode] > parentcost + childcost)
            {
                dis[childnode] = parentcost + childcost;
                pq.push({dis[childnode],childnode});
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
