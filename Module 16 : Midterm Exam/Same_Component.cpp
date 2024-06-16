#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e3+5;
vector<pii> path={{-1,0},{1,0},{0,-1},{0,1}};
bool visited[N][N];
int dis[N][N];
char a[N][N];
int n,m;
bool isValid(int ci,int cj)
{
    if(ci>=0 && ci<n && cj>=0 && cj<m && a[ci][cj]=='.')
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
        pii parent=q.front();
        int pi=parent.first;
        int pj=parent.second;
        q.pop();
        for(auto c: path)
        {
            int ci=pi+c.first;
            int cj=pj+c.second;
            if(isValid(ci,cj) && !visited[ci][cj] && a[ci][cj] == '.')
            {
                visited[ci][cj]=true;
                q.push({ci,cj});
                dis[ci][cj]=dis[pi][pj] + 1;
            }
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
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    bfs(si,sj);
    if(visited[di][dj]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
