#include<bits/stdc++.h>
using namespace std;
const int N=1e3+4;
vector<int> adj[N];
bool visited[N];
int par[N];
int level[N];
void bfs(int src)
{ 
    queue<int>q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    par[src] = -1;
    while(!q.empty())
    {
        int parent=q.front();
        q.pop();
        for(int child: adj[parent])
        {
            if(!visited[child])
            {
                q.push(child);
                par[child]=parent;
                level[child]= level[parent] + 1;
                visited[child] = true;
            }
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
    bfs(1);
    
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"Node "<< i << ": "<<par[i]<<endl;
    // }
    int d;
    cin >> d;
     cout<<"Distance: "<<level[d]<<endl;
    if (visited[d])
    {
        vector<int> path;
        int x = d;
        while (x != -1)
        {
            // cout << x << endl;
            path.push_back(x);
            x = par[x];
        }
        reverse(path.begin(), path.end());
        for (int val : path)
        {
            cout << val << " ";
        }
    }
    else
    {
        cout << "Path nai" << endl;
    }
    return 0;
}
