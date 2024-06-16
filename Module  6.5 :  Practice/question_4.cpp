#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
int depth[N];
void dfs(int parent)
{
    visited[parent] = true;
    for(int child : adj[parent])
    {
        if(visited[child] == true) continue;
        depth[child] = depth[parent] + 1;
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
    dfs(1);
    int x;
    cin>>x;
    for(int i=1;i<=n;i++)

    {
        if(i == x)
        cout<<"Depth of "<< i << " = "<<depth[i]<<endl;
    }
    return 0;
}
