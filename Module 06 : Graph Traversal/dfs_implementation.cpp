#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> adj[N];
bool visited[N];
void dfs(int parent)
{
    // section 1 : actions just after enetering node u
    visited[parent] = true;
    cout<<parent<<" ";
    for(int child: adj[parent])
    {
        // section 2 : actions before entering a neighboure
        if(visited[child] == false) //continue;
       {
         dfs(child);
       }
        // section 3 : actions after existing a neighbor
    }
     // section 4  : actions before existion node u
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
    // for(int i=1;i<=n;i++)
    // {   cout<<"Node "<<i<<": ";
    //     for(int j: adj[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    dfs(1);
    cout<<"visited array"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Node"<< i << " status :"<<visited[i]<<endl;
    }
    return 0;
}
