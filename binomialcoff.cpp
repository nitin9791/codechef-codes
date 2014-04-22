#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
static int c[50][50];
int min(int a,int b){return a<b?a:b;}
int bincoff(int n,int k)
{
    if(k==0 || k==n)
        return 1;
    else return bincoff(n-1,k-1)+bincoff(n-1,k);
}
int bincoff1(int n,int k)
{
    if(c[n][k]==0)
    {
        if(k==0 || k==n)
            c[n][k]=1;
        else
            c[n][k]=bincoff1(n-1,k)+bincoff1(n-1,k-1);
    }
    return c[n][k];
}
int bincoffdp(int n,int k)
{
    int c[50][50],i,j;
    for(i=0;i<=n;i++)
        c[i][0]=c[i][i]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=min(i,k);j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    return c[n][k];
}
int bincoffdp1(int n,int k)
{
    int c[50]={0},i,j;
    c[0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=min(i,k);j>0;j--)
        {
            c[j]=c[j]+c[j-1];
        }
    }
    return c[k];
}
int binomialCoeff(int n, int k)
{
    int* C = (int*)calloc(k+1, sizeof(int));
    int i, j, res;

    C[0] = 1;

    for(i = 1; i <= n; i++)
    {
        for(j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }

    res = C[k];  // Store the result before freeing memory

    free(C);  // free dynamically allocated memory to avoid memory leak

    return res;
}
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cout<<binomialCoeff(n,k)<<" "<<bincoff1(n,k)<<" "<<bincoffdp1(n,k)<<"\n";
    }
    return 0;
}

