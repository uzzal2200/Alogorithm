class Solution {
public:

bool visited[100][100];
vector<pair<int,int>> path={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
bool isValid(int ci,int cj)
{
    if(ci>=0 && ci<n && cj>=0 && cj<m)
    return true;
    else return false;
}
int cnt;
 void dfs(int si, int sj, vector<vector<int>> &grid)
{
  visited[si][sj] = true;
  cnt++;
  for(pair<int,int> c:path)
  {
    int ci=si+c.first;
    int cj=sj+c.second;
    if(isValid(ci,cj) && !visited[ci][cj] && grid[ci][cj]==1)
    {
     dfs(ci,cj,grid);
    }
  } 
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    cnt = 0;
                    dfs(i,j,grid);
                    mx=max(cnt,mx);
                }
            }
        }
        return mx;
    }
};