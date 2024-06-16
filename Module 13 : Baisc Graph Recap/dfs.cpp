#include<bits/stdc++.h>
using namespace std;
const int N =1e4+4;
vector<int> adj[N];
bool visited[N];
void dfs(int src)
{
   visited[src] = true;
   cout<<src<<endl;
   for(int child: adj[src])
   {
    if(visited[child] == false)
    {
        dfs(child);
    }
   }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"Node " << i << ": " <<visited[i]<<endl;
    }
    return 0;
}
