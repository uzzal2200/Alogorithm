#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int INF=1e9+5;
int dis[N][N];
int n;
void matrix()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dis[i][j]== INF) cout<<" x "<<" ";
            else cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}
void initial()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( i != j)
            {
                dis[i][j] = INF;
            }
        }
    }
}
int main()
{
  
    cin>>n;
    initial();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>dis[i][j];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    matrix();
    return 0;
}
