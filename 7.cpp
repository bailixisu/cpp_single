#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 105
#define INF 99999999;
using namespace std;
int M,N;
int qizi=1,s;
struct Goods
{
    int p,l,x;
    int nupr[maxn][2];
}goods[maxn];
bool pds[maxn]={0};
int to(int t,int s)
{
    for(int i=0;i<goods[s].x;i++)
    {
        if(goods[t].nupr[i][0]==s)
            return i;
        else return 0;
    }
}
int main()
{
    while(scanf("%d %d",&M,&N)==2)
    {
        for(int i=1;i<=N;i++)
        {
        cin>>goods[i].p>>goods[i].l>>goods[i].x;
        for(int j=0;j<goods[i].x;j++)
        cin>>goods[i].nupr[j][0]>>goods[i].nupr[j][1];
        }
        goods[0].p=0;goods[0].x=N;goods[0].l=999;
        for(int i=0;i<N;i++)
        {
            goods[0].nupr[i][0]=i+1;
            goods[0].nupr[i][1]=goods[i+1].p;
        }
        s=0;pds[s]=1;
        while(qizi<N+1)
    {
        for(int i=0;i<N;i++)
        {
            int b=to(i,s);
            if(!pds[i]&&b)
            goods[i].p=min(goods[i].p,goods[s].p+goods[i].nupr[b][1]);
        }
        for(int i=0;i<N;i++)
        {
            int da=INF;
            if(!pds[i])
            {
                if(goods[i].p<da)
               {
                    s=i;
                    da=goods[i].p;
                }
            }
        }
        qizi++; pds[s]=1;
    }
    cout<<goods[1].p;
    }
    return 0;
}
