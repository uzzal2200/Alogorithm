#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> adj[N];
bool visited[N];
 int level[N];
void dfs(int parent)
{
   
   queue<int> q;
   q.push(parent);
    visited[parent] = true;
    level[parent]=0;
   
   while(!q.empty())
   {
      int u=q.front();
       q.pop();
        //cout<<"visiting Node "<< u << endl;
     for(int child: adj[u])
    {
        
        if(visited[child] == true) continue;
        q.push(child);
          visited[child] = true;
        level[child]=level[u] + 1;
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
    cout<<"levle of Node"<< i << ": "<<level[i]<<endl;
    }
   
    return 0;
}

