#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> adj[N];
bool visited[N];
vector<int> cmp;
void dfs(int src)
{
    visited[src] = true;
    cmp.push_back(src);
    for(int child:adj[src])
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
       int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            cnt++;
            dfs(i);
            for (int val : cmp)
            {
                cout << val << " ";
            }
            cout << endl;
            cmp.clear();
        }
    }
    cout << cnt << endl;
    return 0;
}
