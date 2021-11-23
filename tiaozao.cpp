#include <cstdio>
#include <cmath>
#include<iostream>
using namespace std;
int main()
{
    long N,M;
    while(scanf("ld% %ld",&N,&M)==2)
    {
        long i;
        double s=0;
        int a[100],j=0;
        for(i=2;i<M;i++)
           {if(M%i==0) a[j++]=i;}
        for(i=0;i<j;i++)
        {
            int k=1;
            while((k++)*a[i]<=M);
            s+=pow(double(k-2),double(N));
        }
        cout<<pow(M,N)-s<<endl;
    }
    return 0;
}
