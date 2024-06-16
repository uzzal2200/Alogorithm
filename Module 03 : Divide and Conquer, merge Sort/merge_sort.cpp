#include<bits/stdc++.h>
using namespace std;
void merged_sort_array(int a1[],int a2[],int sz1,int sz2,int mergedarr[])
{
    int i=0,j=0,k=0;
    while(i < sz1 && j < sz2)
    {
        if(a1[i] <= a2[j])
        {
            mergedarr[k]=a1[i];
    
            i++;
        }
        else
        {
          mergedarr[k] = a2[j];
            j++;
        }
        k++;
    }
    while(i < sz1)
    {
        mergedarr[k]=a1[i];
        i++;
        k++;
    }
       while(j < sz2)
    {
        mergedarr[k]=a1[j];
        j++;
        k++;
    }
}
int main()
{
    int a1[]={1,3,5,7,9};
    int sz1= sizeof(a1) / sizeof(a1[0]);
    //cout<<sz1;
    int a2[]={2,4,6,8,10};
    int sz2=sizeof(a2) / sizeof(a2[0]);
    int mergedsize=sz1+sz2;
   //  cout<<mergedsize<<endl;
    int mergedarr[mergedsize];
    merged_sort_array(a1,a2,sz1,sz2,mergedarr);
    for(int i=0;i<mergedsize;i++)
    {
        cout<<mergedarr[i]<<" ";
    }
    return 0;
}
