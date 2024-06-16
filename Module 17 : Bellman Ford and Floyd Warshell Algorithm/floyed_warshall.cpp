#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int INF=1e9+5;
int dis[N][N];
 int n,e;
  void matrix()
 {
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
          
          if(dis[i][j] == INF) cout<<"INF ";
           else cout<<dis[i][j]<<" ";
        }
         cout<<endl;
    }
 }
 void initial()
 {
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
          if(i != j)
            dis[i][j]=INF;
            
        }
       
    }
 }

int main()
{
     cin>>n>>e;
     initial();
     while(e--)
     {
        int a,b,w;
        cin>>a>>b>>w;
        dis[a][b]=w;
     }
     cout<<"Before Floyed Warshall algorithm"<<endl;
     // floyed algorithm apply
      matrix();
       for(int k=1;k<=n;k++)
       {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]= min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
       }
       cout<<"After applying  Floyed warshall Algorithm"<<endl;
       matrix();
    return 0;
}
