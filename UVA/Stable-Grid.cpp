//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3187

#include <cstdio>

using namespace std;

int cases;
int nums[105][105], n, num, totes, cont[105];

int main()
{
	scanf("%d", &cases);
	for(int q=1; q<=cases; q++)
	{
		scanf("%d", &n);
		totes=1;
		for(int i=0; i<=100; i++)
			cont[i]=0;
		for(int i=1; i<=n*n; i++)
		{
			scanf("%d", &num);
			cont[num]++;
			if(cont[num]>n)
				totes=0;
		}
		if(totes)
			printf("Case %d: yes\n", q);
		else
			printf("Case %d: no\n", q);
	}
}
