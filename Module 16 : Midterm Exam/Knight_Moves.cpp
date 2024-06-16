#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e3+5;
bool visited[N][N];
int level[N][N];
vector<pii> direc = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int n, m;
bool isValid(int ci,int cj)
{
    return (ci>=0 && ci<n && cj>=0 && cj<m);
   
}
void bfs(int si,int sj)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            visited[i][j] = false;
            level[i][j] = -1;
        }
    }
    
  queue<pii> q;
  q.push({si,sj});
  visited[si][sj]=true;
  level[si][sj]=0;
  while(!q.empty())
  {
    pii parent = q.front();
    int pi=parent.first;
    int pj=parent.second;
    q.pop();
    for(auto c: direc)
    {
        int ci=pi+c.first;
        int cj=pj+c.second;
        if(isValid(ci,cj) && !visited[ci][cj])
        {
            visited[ci][cj]= true;
            q.push({ci,cj});
            level[ci][cj]=level[pi][pj]+1;
        }
    }
  }
}
int main()
{
    int t;
    cin>>t;
     for(int i=0;i<t;i++)
     {
        cin>>n>>m;
        int ki,kj,qi,qj;
        cin>>ki>>kj>>qi>>qj;
        bfs(ki,kj);
       if(visited[qi][qj]) cout<<level[qi][qj]<<endl;
       else cout<<"-1"<<endl;
     }
    return 0;
}
