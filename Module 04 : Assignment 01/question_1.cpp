#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int mid,int r)
{
    int l_size=mid-l+1;
    int r_size=r-mid;
    int L[l_size + 1],R[r_size + 1];
    int k=0;
    for(int i=l;i<=mid;i++)
    {
        L[k]=a[i];
        k++;
    }
    k=0;
    for(int i=mid+1;i<=r;i++)
    {
        R[k]=a[i];
        k++;
    }
    int i=0,j=0;
    int cur=l;
    while(i < l_size && j < r_size)
    {
        if(L[i] >= R[j])
        {
            a[cur]=L[i];
            i++;
        }
        else 
        {
            a[cur] = R[j];
            j++;
        }
        cur++;
    }
    while(i < l_size)
    {
        a[cur]=L[i];
        i++;
        cur++;
    }
     while(j < r_size)
    {
        a[cur]=R[j];
        j++;
        cur++;
    }
}
void sortmerge(int a[],int l,int r)
{
    if(l == r) return;
    int mid=(l+r)/2;
    sortmerge(a,l,mid);
    sortmerge(a,mid+1,r);
    merge(a,l,mid,r);
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
    sortmerge(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
