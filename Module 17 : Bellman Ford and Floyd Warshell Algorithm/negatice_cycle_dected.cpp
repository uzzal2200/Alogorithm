

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=13+3;
const int INF=INT_MAX;
vector<pair<pii,int> > edges;
int dis[N];
int n,e;
void bellmanford(int src)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]= INF;

    }
    dis[src]=0;
    for(int i=1;i<n;i++)
    {
        // all path relaxtion 
        for(auto ed: edges)
        {
            int a=ed.first.first;
            int b=ed.first.second;
            int w=ed.second;
            if(dis[b] > dis[a] + w )
            {
                dis[b]= dis[a] + w;
            }

        }
    }
    bool cycle= false;

     for(auto ed: edges)
        {
            int a=ed.first.first;
            int b=ed.first.second;
            int w=ed.second;
            if(dis[b] > dis[a] + w )
            {
                cycle = true;
                break;
                dis[b]= dis[a] + w;
            }

        }
     if(cycle) cout<<"cycle exisit"<<endl;
     else
     {
        for(int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<": "<<dis[i]<<endl;
    }
     }
}


int main()
{
    cin>>n>>e;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edges.push_back({{a,b},w});

    }
    bellmanford(1);

    
    return 0;
}