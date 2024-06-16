#include<bits/stdc++.h>
using namespace std;
const int N = 135+5;
vector<int> g[N];
vector<bool> visited(N,false);
vector<int> level(N,0);
// int parent[N];
vector<int> parent(N,-1);
int n,m;
bool bfs()
{
    queue<int> q;
    q.push(1);
    level[1] =0;
       //parent[source] = -1;
    visited[1]=true;
   
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        
        for(int child: g[u])
        {
            if(visited[child]) continue;
            q.push(child);
            visited[child] = true;
            parent[child] = u;
            level[child] = level[u] + 1;
        }
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)

    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    if(bfs())
    {
         int current=n;
     vector<int>path;
    while(current != -1)
    {
        path.push_back(current);
       current=parent[current];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;

    for(int val: path)
    {
        cout<<val<<" ";
    }

    }

   else
   {
    cout<<"IMPOSSIBLE";
   }
 
   
    return 0;
}
