#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e2+5;
const int INF=INT_MAX;
vector<pair<pii,int> > v;
int dis[N];
int n,e;
void bellmenford(int src)
{
    for(int i=1;i<=n;i++)
    {
     dis[i]=INF;
    }
}
int main()
{
    cin>>n>>e;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v.push_back({{a,b},w});
    }
    bellmenford(1);
    return 0;
}