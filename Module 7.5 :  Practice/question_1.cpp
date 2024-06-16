#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
bool visited[N];
vector<int> adj[N];
int bfs(int parent)
{
    queue<int> q;
    q.push(parent);
    visited[parent] = true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        // cout<<u<<" ";
        return u;
        for(int child: adj[u])
        {
            if(visited[child] == true) continue;
            q.push(child);
            visited[child] = true;
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
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        //cout<<bfs(i)<<" ";
        v.push_back(i);
    }
    reverse(v.begin(),v.end());
    for(int val: v)
    {
        cout<<val<<" ";
    }
    return 0;
}

