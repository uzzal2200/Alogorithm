#include<bits/stdc++.h>
using namespace std;
const int N=1e3+4;
int adj[N][N];
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
       adj[a][b]=1;
       adj[b][a]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

