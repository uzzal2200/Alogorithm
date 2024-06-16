#include<bits/stdc++.h>
#define pii pair<int,int> 
using namespace std;
const int N=1e3+5;
bool visited[N][N];
int dis[N][N];
vector<pii> path={{-1,0},{1,0},{0,-1},{0,1}};
 int n,m;
 bool isValid(int ci,int cj)
 {
    if(ci>=0 && ci<n && cj>=0 && cj<m)
    return true;
    else return false;
 }
void bfs(int si,int sj)
{
  queue<pii> q;
  q.push({si,sj});
  visited[si][sj]=true;
  dis[si][sj]=0;
  while(!q.empty())
  {
    pii parent = q.front();
    
    int pi=parent.first;
    int pj=parent.second;
    q.pop();
    for(auto c:path)
    {
        int ci=pi + c.first;
        int cj=pj + c.second;
       if(isValid(ci,cj) && !visited[ci][cj])
       {
        visited[ci][cj] = true;
        q.push({ci,cj});
        dis[ci][cj]=dis[pi][pj] + 1;
       }
    }

  }

}
int main()
{
   
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
     }
    return 0;
}
