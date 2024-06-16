#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=1e3+5;
vector<pii> adj[N];
long long int dis[N];
bool visited[N];
int n;
long long int e;
void dijkstra(int src)
{
    for(int i=1;i<=n;i++)
    {
     dis[i]=LLONG_MAX;
     visited[i]= false;
    
    }
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,src});
    dis[src]=0;
    while(!pq.empty())
    {
        pii parent=pq.top();
        pq.pop();
        int parentnode=parent.second;
        if(visited[parentnode] == true) continue;
        visited[parentnode] = true;
         int parentcost=parent.first;
        for(pii child : adj[parentnode])
        {
            int childnode=child.first;
            int childcost = child.second;
            if(dis[childnode] > childcost + parentcost)
            {
                dis[childnode] = childcost + parentcost;
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

   int src;
   cin>>src;
      dijkstra(src);
    int q;
   cin>>q;
   for(int i=0;i<q;i++)
   {
     int des;
     long long int cost;
    cin>>des>>cost;
 
    if(dis[des] <= cost) 
    {

        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

   }
    return 0;
}
