#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> adj[N];
bool visited[N];

bool dfs(int parent,int u=-1)
{
    bool cycleExist = false;
  visited[parent] = true;
  for(int child: adj[parent])
  {
    if(child == u) continue;
    if(visited[child] == true) return true;
    cycleExist=cycleExist | dfs(child,parent);
    
  }
  return cycleExist;
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
//   if(dfs(1))
//   {
//     cout<<" cycle detected"<<endl;
//   }
//   else cout<<"No cycle detece"<<endl;
bool isCycle = false;
for(int i=1;i<=n;i++)
{
    if(visited[i]) continue;
    isCycle |= dfs(i);
}
if(isCycle)  cout<<" cycle detected"<<endl;
else cout<<"No cycle detece"<<endl;
    return 0;
}
