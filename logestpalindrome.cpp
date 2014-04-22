#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int main()
{
    int t,i,j,n,c;
    char s[100];
    int l[100][100];
    cin>>t;
    while(t--)
    {
        fflush(stdin);
        gets(s);
        n=strlen(s);
        for(i=0;i<n;i++)
            l[i][i]=1;

        for(c=2;c<=n;c++)
        {
            for(i=0;i<n-c+1;i++)
            {
                j=i+c-1;
                if(s[i]==s[j])
                    l[i][j]=l[i+1][j-1]+2;
                else
                    l[i][j]=max(l[i+1][j],l[i][j-1]);
            }

        }
        cout<<l[0][n-1]<<"\n";
    }
    return 0;
}
