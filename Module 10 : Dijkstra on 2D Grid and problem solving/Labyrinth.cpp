#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e4+5;
vector<string> g;
vector<pii> direction={{0,-1},{0,1},{-1,0},{1,0}};
pii parent[N][N];
int level[N][N];
int visited[N][N];
int n,m;
bool isVaild(int i,int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}
 void bfs (int si,int sj)
 {
    queue<pii> q;
    q.push({si,sj});
    visited[si][sj] = true;
    level[si][sj]= 0;
    while(!q.empty())
    {
        pii upair= q.front();
        int i=upair.first;
        int j=upair.second;
        q.pop();
        for(auto d: direction)
        {
            int ni=i+d.first;
            int nj=j+d.second;
            if(isVaild(ni,nj) && !visited[ni][nj] && g[ni][nj]!='#')
            {
                q.push({ni,nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj]={i,j};
            }
        }
    }
 }
int main()
{
    int si,sj,di,dj;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        for(int j=0;j<m;j++)
        {
            if(x[j] == 'A')
            si=i;
            sj=j;
            if(x[j] == 'B')
            di=i;
            dj=j;
        }
        g.push_back(x);
    }
    bfs(si,sj);
   cout<<level[di][dj]<<endl;
    return 0;
}
