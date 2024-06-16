#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+5;
ll save[N];
ll fibonacci(ll n)
{
    // base case 
    if(n==0 || n==1) return 1;
    //if(n<=1) return 1;
    if(save[n] != -1 )
    {
        return save[n];
    }
    ll ans1=fibonacci(n-1);
    ll ans2=fibonacci(n-2);
    save[n] = ans1+ans2;
    return save[n];

}
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
      save[i]=-1;
    }
    cout<<fibonacci(n)<<endl;
    return 0;
}
