#include<bits/stdc++.h>
void mergesort(int a[],int b[],int n,int m,int merge[])
{
    int i=0,j=0,k=0;
    while(i < n && j < m)
    {
        if(a[i] >= b[j])
        {
            merge[k] = a[i];
            i++;
        }
        else
        {
            merge[k]=b[j];
            j++;
        }
        k++;
    }
      while(i < n)
      {
        merge[k] = a[i];
        i++;
        k++;
      }
    while ( j < m)
    {
        merge[k]=b[j];
        j++;
        k++;
    }
}
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
      int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int r=n+m;
    int merge[r];
    mergesort(a,b,n,m,merge);
    for(int i=0;i<r;i++)
    {
        cout<<merge[i]<<" ";
    }
    return 0;
}
