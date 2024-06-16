#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N=1e3+5;
vector<pi> path={{-1,0},{1,0},{0,-1},{0,1}};
bool visited[N][N];
char a[N][N];
int n,e;
int cnt;
bool isValid(int ci,int cj)
{
    if( ci>=0 && ci<n && cj>=0 && cj<e && a[ci][cj] == '.') return true;
    else return false;
    
}
void dfs(int si,int sj)
{
  visited[si][sj]=true;
  cnt++;
  for(pi c: path)
  {
    int ci=si+c.first;
    int cj=sj+c.second;
    if(isValid(ci,cj) && !visited[ci][cj] && a[ci][cj]=='.')
    {
        dfs(ci,cj);
    }
  }
}
int main()
{
    cin>>n>>e;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            cin>>a[i][j];
        }
    }
    int mn=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(!visited[i][j] && a[i][j]=='.')
            {
                cnt=0;
                dfs(i,j);
                mn=min(cnt,mn);
            }
        }
    }
  if(cnt > 0)  cout<<cnt<<endl;
  if(cnt == 0) cout<<"-1";
    return 0;
}
