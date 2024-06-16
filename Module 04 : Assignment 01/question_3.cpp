#include<bits/stdc++.h>
using namespace std;
int first(int a[],int n, int x)
{
    int l=0,r=n-1;
    int cnt=0;
    while(l <= r)
    {
        int mid=(l+r)/2;
        if(a[mid] == x)
        {
            cnt++;
            r=mid-1;
        }
        else if(x > a[mid])
        {
            l=mid+1;

        }
        else
        {
            r=mid-1;
        }
    }
    return cnt;
}
int second(int a[],int n, int x)
{
    int l=0,r=n-1;
    int cnt=0;
    while(l <= r)
    {
        int mid=(l+r)/2;
        if(a[mid] == x)
        {
            cnt++;
            l=mid+1;
        }
        else if(x > a[mid])
        {
            l=mid+1;

        }
        else
        {
            r=mid-1;
        }
    }
    return cnt;
}
int main()
{
     int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;
    
   int r1= first(a,n,x);
   int r2= second(a,n,x);
   int mx=max(r1,r2);
     if( mx > 1)
     {
        cout<<"YES"<<endl;
     }
     else
     {
        cout<<"NO"<<endl;
     }
    return 0;
}
