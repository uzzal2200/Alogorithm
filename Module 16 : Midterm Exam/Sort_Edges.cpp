#include<bits/stdc++.h>
using namespace std;
int main()
{
    int e;
    cin>>e;
    vector<pair<int,int> > edge;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        edge.push_back({a,b});
    }
    sort(edge.begin(),edge.end());
    for(auto val:edge)
    {
        cout<<val.first<<" "<<val.second<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int main()
{
    int e;
    cin>>e;
    priority_queue<pi,vector<pi>,greater<pi> > pq;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        pq.push({a,b});
    }
    while(!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;

        pq.pop();
   }
    return 0;
}
