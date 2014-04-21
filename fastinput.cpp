#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
int scan_int()
{
    char c;
    int r=0;
    while(1)
    {
        c=getchar_unlocked();
        if(c=='\n'|| c==' ')
        break;
        r=(r<<3)+(r<<1)+c-48;
    }
    return r;
}
bool mg[21][21];
int m,N[21]={0};
vector<int> a;
int finans=1;
void BronKerbosch(int r,int p,int x)
{
    if(x==0 && p==0)  a.push_back(r); return;
    int v;
    for(int v=0;v<m;v++)
    {
        if(p&(1<<v))
        {
            return BronKerbosch(r|(1<<v),p&N[v],x&N[v]);
            p=p&(~(1<<v));
            x=x|(1<<v);
        }
    }

}
int main()
{
    int n,i,j,k,t;
    int p,r,x;
    freopen("Input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    int offer[200001]={0};
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        mg[i][j]=true;
    }
    //int offer[21];
    for(i=0;i<m;i++)
    {
       scanf("%d",&k);
        //k=scan_int();
        for(j=0;j<k;j++)
        {
            scanf("%d ",&t);
            offer[t]=offer[t]|(1<<i);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(offer[k]&(1<<i) && offer[k]&(1<<j))
                {
                        mg[i][j]=mg[j][i]=false;
                        break;
                }
            }

        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(mg[i][j])
            {
                N[i]=N[i]|(1<<j);
            }
        }
    }
   /* for(i=0;i<m;i++)
    {
        cout<<N[i]<<" ";
        for(j=0;j<m;j++)
            cout<<mg[i][j]<<" ";
        cout<<"\n";
    }
    /*for(i=0;i<m;i++)
    {
        cout<<N[i]<<"\n";
    }*/
    p=(1<<m)-1;
    r=0;
    x=0;
   // cout<<p<<"\n";
   //for(i=0;i<m;i++)
    //    dfs(i,1<<i,1);
    BronKerbosch(r,p,x);
    for(i=0;i<a.size();i++)
        cout<<a[i];
    //for(i=0;i<m;i++)
    //maxCompleteGraph(i,1<<i,1);
    cout<<ans<<"\n";
    //cout<<p<<r<<x;
    /*res=0;
    while(ans)
    {
        if(ans&1)
            res=res+1;
        ans=ans>>1;
    }
    cout<<res<<"\n";*/
    return 0;
}
