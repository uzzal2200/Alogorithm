#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=1e3+5;
bool visited[N][N];
vector<pii> path={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
char a[N][N];
bool isValid(int ci,int cj)
{
    if(ci>=0 && ci<n && cj>=0 && cj<m && a[ci][cj]=='.')
    return true;
    else return false;
}
void dfs(int si,int sj)
{
  visited[si][sj] = true;
  for(pii c:path)
  {
    int ci=si+c.first;
    int cj=sj+c.second;
    if(isValid(ci,cj) && !visited[ci][cj])
    {
        dfs(ci,cj);
    }
  } 
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j] == false && a[i][j]=='.')
            {
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
