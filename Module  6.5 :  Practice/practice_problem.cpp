#include<bits/stdc++.h>
using namespace std;
const int N=1e+5;
vector<int> adj[N];
bool visited[N];
 int dfs(int parent)
{
  
  visited[parent] = true;
//  cout<<parent<<" ";
return parent;
 
  for(int child: adj[parent])
  {
    if(visited[child] == true) continue;
    dfs(child);
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
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
      // cout<< dfs(i)<<" ";
      v.push_back(i);
    }
    reverse(v.begin(),v.end());
   for(int val:v)
   {
    cout<<val<<" ";
   }
  
    return 0;
}
