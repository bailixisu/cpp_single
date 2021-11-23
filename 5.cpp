#include <iostream>
#include<vector>
using namespace std;
int x,y,m,n,L;
int main()
{
    int i=0;
    while(scanf("%d %d %d %d %d",&x,&y,&m,&n,&L)!=EOF)
    {
        vector<int> a(L);
        do
        a[i]=(x-y+i*(m-n))%L;
        while(a[i++]!=0);
        if(i==L+1) cout<<"Impossible";
        else cout<<i-1;
    }
    return 0;
}
