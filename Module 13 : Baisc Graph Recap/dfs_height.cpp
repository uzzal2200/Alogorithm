#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> adj[N];
bool visited[N];
int height[N];
void dfs(int parent)
{
   
    visited[parent] = true;
   
    for(int child: adj[parent])
    {
       
        if(visited[child] == false)
        {
          dfs(child);
          height[parent]=max(height[parent],height[child] + 1);
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
   
    dfs(1);
    for(int i=1;i<=n;i++)
    {
 cout<<"Height of node"<< i <<": "<<height[i]<<endl;
    }
   
    return 0;
}
