#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
vector<int> adj[N];
void dfs(int src)
{
    visited[src] = true;
    for (int child : adj[src])
    {
        if (visited[child] == false)
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i);
            ans.push_back(i);
        }
    }
    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
    return 0;
}
