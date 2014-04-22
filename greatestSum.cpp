#include<iostream>
#include<limits.h>
using namespace std;
void gSum(int a[],int n,int *ms)
{
    int sum[n+1],i,j,t;
    for(i=0;i<n;i++)
        sum[i]=a[i];
    for(i=0;i<n;i++)
    {
        t=sum[i];
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i] && sum[i]+sum[j]>t)
            t=sum[i]+sum[j];
        }
        sum[i]=t;
        if(*ms<sum[i])
            *ms=sum[i];
    }
}
int main()
{
    int arr[]={1, 101, 2, 3, 100, 4, 5},ms=0;
    int n=sizeof(arr)/sizeof(int);
    gSum(arr,n,&ms);
    cout<<"Max Sum is  "<<ms;
    return 0;

}
