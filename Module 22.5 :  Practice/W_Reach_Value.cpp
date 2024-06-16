#include<bits/stdc++.h>
using namespace std;
bool solve(long long  n,long long  cur)
{
    if(cur >= n)
    {
       if(cur == n) return true;
        else return false;
    }
      bool op1=solve(n,cur*10);
      bool op2=solve(n,cur*20);
      return op1 || op2;
    }
  
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long  n;
        cin>>n;
      bool ans = solve(n,1);
      if(ans) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    return 0;
}
