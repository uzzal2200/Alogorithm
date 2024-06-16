#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
vector<int> adj[N];
bool visited[N];
int level[N];
 void  bfs(int parent,int l)
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
   vector<int>v;
 
  int l;
  cin>>l;
   bfs(0,l);
  for(int i=0;i<n;i++)
  {
    if(level[i] == l)
    {
      v.push_back(i);
    }
  }
    if(v.empty())
    {
        cout<<" -1 "<<endl;
    }
    else
    {
        for(int val: v)
        {
            cout<<val<<" ";
        }
    }
    return 0;
}