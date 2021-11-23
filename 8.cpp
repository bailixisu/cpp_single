#include <iostream>
#include <cstring>
#define maxn 50005
#define maxk 100005
using namespace std;
int n,k;
struct Hua
{
    int zl,x1,x2;
}hua[maxk];
bool zj[maxk];
int mod[maxn];
int main()
{
    while(scanf("%d %d",&n,&k)==2)
    {
        for(int i=1;i<=k;i++)
            cin>>hua[i].zl>>hua[i].x1>>hua[i].x2;
        memset(zj,1,sizeof(zj));
        memset(mod,-1,sizeof(mod));
        for(int i=1;i<=k;i++)
            if((hua[i].x1>n||hua[i].x2>n)||(hua[i].zl==2&&hua[i].x1==hua[i].x2))
                zj[i]=0;
        for(int i=1;i<=k;i++)
        {
            if(zj[i]==1)
            {
                if(mod[hua[i].x1]==-1&&mod[hua[i].x2]==-1)
                {
                    mod[hua[i].x1]=1;
                    mod[hua[i].x2]=hua[i].zl;
                }
                else if(mod[hua[i].x1]==-1)
                {
                    mod[hua[i].x1]=(mod[hua[i].x2]-hua[i].zl+1)%3;
                    if(mod[hua[i].x1]==-1) mod[hua[i].x1]=2;
                }
                else if(mod[hua[i].x2]==-1)
                    mod[hua[i].x2]=(mod[hua[i].x1]+hua[i].zl-1)%3;
                else
                    zj[i]=!(mod[hua[i].x2]-(mod[hua[i].x1]+hua[i].zl-1)%3);
            }
        }
        int s=0;
        for(int i=1;i<=k;i++)
            s+=zj[i];
        cout<<k-s<<endl;
    }
    return 0;
}
