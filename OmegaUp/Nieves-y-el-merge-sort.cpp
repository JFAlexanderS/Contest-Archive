//https://omegaup.com/arena/problem/Nieves-y-el-merge-sort

#include <cstdio> 

using namespace std;

int nums;
int llist[1000005], back[1000005];

void ms(int l, int r)
{
	if(l==r)
		return;
	int m=(l+r)/2;
	ms(l, m);
	ms(m+1, r);
	for(int i=l, j=r, b=l; b<=r; b++)
	{
		if(i>m || (llist[j]<llist[i] && j!=m))
		{
			back[b]=llist[j];
			j--;
		}
		else
		{
			back[b]=llist[i];
			i++;
		}
	}
	for(int i=l; i<=r; i++)
		llist[i]=back[i];
}

int main()
{
	scanf("%d", &nums);
	for(int i=1; i<=nums; i++)
		scanf("%d", &llist[i]);
	ms(1, nums);
	for(int i=1; i<=nums; i++)
		printf("%d ", llist[i]);
	printf("\n");
	return 0;
}
