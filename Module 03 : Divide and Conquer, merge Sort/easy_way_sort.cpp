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
    L[l_size]=INT_MAX;
    R[r_size]=INT_MAX;
    int lp=0,rp=0;
    for(int i=l;i<=r;i++)
    {
        if(L[lp] <= R[rp])
        {
            a[i]=L[lp];
            lp++;

        }
        else
        {
            a[i]=R[rp];
            rp++;
        }
    }
}
void sortmerge(int a[],int l,int r)
{
    if(l == r) return;
    int mid=(l+r)/2;
    sortmerge(a,l,mid);
    sortmerge(a,mid+1,r);
    merge(a,l,mid,r);
    //  cout<<"This"<<endl;
    //     for(int i=l;i<=mid;i++)
    //     {
    //         cout<<a[i]<<" ";
    //     }
    //     cout<<endl;
    //     for(int i=mid+1;i<=r;i++)
    //     {
    //         cout<<a[i]<<" ";
    //     }
    //     cout<<endl;
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
