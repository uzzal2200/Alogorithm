#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
vector<int> adj[N];
bool visited[N];
int level[N];
  bfs(int parent)
{
  queue<int>q;
  q.push(parent);
 visited[parent] = true;
 while(!q.empty())
 {
    int u=q.front();
    q.pop();
  
    for(int child: adj[u])
    {

        if(visited[child] == true) continue;
        q.push(child);
        visited[child] = true;
        level[child] = level[u] + 1;
    }
 }

}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
  
    // for(int i=1;i<=n;i++)
    // {
    //  cout<<i<<" : "<<level[i]<<endl;
    // }
    int q;
    cin>>q;
   
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        bfs(x);
        cout<<level[y]<<endl;
   
    }
    return 0;
}
