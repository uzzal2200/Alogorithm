#include<bits/stdc++.h>
using namespace std;
 int find(int a[],int n,int x)
 {
    int l=0;
    int r=n-1;
    while(l <= r)
    {
        int mid=(l+r)/2;
        if(a[mid] == x) return mid;
        else if(x > a[mid] ) l=mid+1;
        else r=mid-1;
    }
   return -1;
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
    
    int result=find(a,n,x);
    if(result != -1)
    {
        cout<<result<<endl;
    }
    else 
    {
        cout<<"Not Found"<<endl;
    }

    return 0;
}
