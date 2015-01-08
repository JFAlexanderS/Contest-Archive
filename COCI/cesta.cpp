//http://hsin.hr/coci/

#include <cstdio>
#include <algorithm>

using namespace std;

char inp[1000005];
int len, digsum;

bool hp(int i, int j)
{
	return i>j;
}

int main()
{
	scanf("%s", inp);
	for(int i=0; inp[i]; i++)
	{
		len=i;
		digsum+=inp[i]-'0';
	}
	sort(inp, inp+len+1, hp);
	if(inp[len]!='0' || digsum%3!=0)
		printf("-1\n");
	else
	{
		for(int i=0; inp[i]; i++)
			printf("%c", inp[i]);
		printf("\n");
	}
}
