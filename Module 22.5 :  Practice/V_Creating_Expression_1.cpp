#include<bits/stdc++.h>
using namespace std;
int a[21];
 int n,x;
bool check_result(long long int sum,int i)
{
    if(i == n)
    {
        return sum==x;
    }
   bool op1=check_result(sum + a[i],i+1);
   bool op2=check_result(sum - a[i],i+1);
   return op1 || op2;
}

int main()
{
   
    cin>>n>>x;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    if(check_result(a[0],1)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}
