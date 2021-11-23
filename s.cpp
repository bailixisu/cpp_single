#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 50010

struct node
{
	int pre;
	int relation;
};
node p[N];

int find(int x) //���Ҹ����
{
	int temp;
	if(x == p[x].pre)
		return x;
	temp = p[x].pre; //·��ѹ��
	p[x].pre = find(temp);
	p[x].relation = (p[x].relation + p[temp].relation) % 3; //��ϵ�����
	return p[x].pre; //�����
}

int main()
{
	int n, k;
	int ope, a, b;
	int root1, root2;
	int sum = 0; //�ٻ�����
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) //��ʼ��
	{
		p[i].pre = i;
		p[i].relation = 0;
	}
	for(int i = 1; i <= k; ++i)
	{
		scanf("%d%d%d", &ope, &a, &b);
		if(a > n || b > n) //����2
		{
			sum++;
			continue;
		}
		if(ope == 2 && a == b) //����3
		{
			sum++;
			continue;
		}
		root1 = find(a);
		root2 = find(b);
		if(root1 != root2) // �ϲ�
		{
			p[root2].pre = root1;
			p[root2].relation = (3 + (ope - 1) +p[a].relation - p[b].relation) % 3;
		}
		else
		{
			if(ope == 1 && p[a].relation != p[b].relation)
			{
				sum++;
				continue;
			}
			if(ope == 2 && ((3 - p[a].relation + p[b].relation) % 3 != ope - 1))
			{
				sum++;
				continue;}
		}
	}
	printf("%d\n", sum);
	return 0;
}
