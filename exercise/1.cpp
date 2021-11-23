#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000
#define W 1000
using namespace std;
int weight[N],value[N];
int w,n; //w是背包容量，n是商品数量。
int DP()   //动态规划解决问题
{
    int tu[N][W];  //创建图
    memset(tu,0,sizeof(tu)); //清0
    for(int i=1;i<=w;i++)
        tu[1][i]=(i>=weight[1]?value[i]:0);  //初始化第一行
    for(int i=2;i<=n;i++)
        for(int j=1;j<=w;j++)
    {
        if(j-weight[i]>=0)
        tu[i][j]=max(tu[i-1][j],value[i]+tu[i-1][j-weight[i]]);
        else tu[i][j]=tu[i-1][j];
    }
    return tu[n][w];
}
int main()
{
    int maxt;
    scanf("%d %d",&w,&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&weight[i],&value[i]); //输入初始数据。
    maxt=DP();
    printf("%d",maxt);
    return 0; 
}
