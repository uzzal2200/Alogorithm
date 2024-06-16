#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> adj[N];
bool visited[N];
 int level[N];
 int parent[N];
void dfs(int s)
{
   
   queue<int> q;
   q.push(s);
    visited[s] = true;
    level[s]=0;
    parent[s]=-1;
   
   while(!q.empty())
   {
      int u=q.front();
       q.pop();
        
     for(int child: adj[u])
    {
        
        if(visited[child] == true) continue;
        q.push(child);
          visited[child] = true;
        level[child]=level[u] + 1;
        parent[child] = u;
    }
   }
   
}
// complexity O(n+m)
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
   
   int s,d;
   cin>>s>>d;
   dfs(s); // total complexiy of dfs O(n+m)
   cout<<"Distance: "<<level[d]<<endl;
   // kar parent ke sheta dekhar jonno
//    for(int i=1;i<=n;i++)
//    {
//     cout<<"parent of"<< i << ": " << parent[i];
//     cout<<endl;
//    } 
// complexity O(n)
vector<int> path;
int current=d;
while(current != -1)
{
     path.push_back(current);
     current=parent[current];
}

reverse(path.begin(),path.end());
//cout<<path.size()<<endl;
for(int val:path)
{
    cout<<val<<" ";
}

    return 0;
}

