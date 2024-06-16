#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const long long INF=1e18+5;
long long dis[N][N];
 int n,e;
 void print_matrix()
 {
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dis[i][j]==INF) cout<<"X"<<" ";
           else  cout<<dis[i][j]<<" ";
        }
    }
 }
 void initial()
 {
    for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=n;j++)
       {
         if(i != j)
         {
            dis[i][j]=INF;
         }
       }
    }
 }
int main()
{
    cin>>n>>e;
    initial();
    while(e--)
    {
    int a,b;
    long long w;
    cin>>a>>b>>w;
      dis[a][b]=min(dis[a][b],w);
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int q;
    cin>>q;
    while(q--)
   {
     int x,y;
     cin>>x>>y;
     if(dis[x][y] == INF) cout<<"-1"<<endl;
     else cout<<dis[x][y]<<endl;
   }
    return 0;
}
