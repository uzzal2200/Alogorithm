#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
vector<int> adj[N];
bool visited[N];
void dfs(int parent)
{
    visited[parent] =true;
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
     //dfs(1);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue;
        dfs(i);
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
