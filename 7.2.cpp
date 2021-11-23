#include<iostream>  
#include<cmath>  
#define INF 200000000  
#define MAX 101  
using namespace std;  
int map[MAX][MAX],lev[MAX],d[MAX],value[MAX];  
bool within_lim[MAX],v[MAX];//within_lim为满足等级限制的标记数组  
int lev_lim,n;  
int dijkstra()//Dijkstra算法  
{  
    int minimum = INF;  
    memset(v,0,sizeof(v));//清除所有点的标号  
    for(int i = 1;i <= n;++i)      
        d[i] = (i == 1 ? 0 : INF);//设d[0] = 0,其他d[i] = INF  
    for(int i = 1;i <= n;++i)//循环N次  
    {  
        int x = 0, m = INF;  
        for(int y = 1; y <= n;++y)  
            if(!v[y] && d[y] <= m && within_lim[y])//在所有未标号且满足等级限制的结点中，选出d值最小的结点x  
            {  
                x = y;  
                m = d[y];  
            }  
        v[x] = 1;//给结点x标记  
        for(int y = 1;y <= n;++y)//对于从x出发的所有边(x,y)，更新d[y] = min{d[y], d[x] + map[x][y])  
        {  
            if(within_lim[y])//满足等级限制  
                d[y] = min(d[y],d[x] + map[x][y]);//更新d[y]值  
        }  
    }  
    for(int i = 1;i <= n;++i)  
    {  
        d[i] += value[i];//对于每个d[i]值，还需加上进入该结点的花费，再进行比较  
        if(d[i] < minimum)   minimum = d[i];  
    }  
    return minimum;  
}  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    //freopen("out.txt","w",stdout);  
    cin >> lev_lim >> n;  
    for(int i = 0;i <= n;++i)  
        for(int j = 0;j <= n;++j)  
            map[i][j] = (i == j ? 0 : INF);//图的初始化，注意对角线初始化为0，从自己出发到自己的花费为0  
    for(int i = 1;i <= n;++i)  
    {  
        int t;  
        cin >> value[i] >> lev[i] >> t;  
        for(int j = 1;j <= t;++j)  
        {  
            int k;  
            cin >> k;  
            cin >> map[i][k];  
        }  
    }//建图完毕  
      
    int kinglev = lev[1];  
    int min_cost = INF,cost;  
    for(int i = 0;i <= lev_lim;++i)  
    {  
        memset(within_lim,0,sizeof(within_lim));//初始化标记数组  
        for(int j = 1;j <= n;++j)  
            if(lev[j] >= kinglev - lev_lim + i && lev[j] <= kinglev + i)//枚举等级允许范围的结点  
                within_lim[j] = 1;  
          
        cost = dijkstra();  
        if(cost < min_cost)  
            min_cost = cost;  
    }  
    cout << min_cost << endl;  
    return 0;  
}  
