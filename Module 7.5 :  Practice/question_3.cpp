#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
bool visited[N];
vector<int> adj[N];
int bfs(int parent,int u=-1)
{
    bool cycleExist = false;
    visited[parent] = true;

        
        for(int child: adj[u])
        {
            if(child == u) continue;
            if(visited[child] == true) return true;
            cycleExist= cycleExist || bfs(child,parent);
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
  // bfs(1);
//   
  bool cycle= false;
  for(int i=1;i<=n;i++)
  {
    if(visited[i]) continue;
    cycle=cycle || bfs(i);
  }
  if(cycle)
  cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
    return 0;
}

