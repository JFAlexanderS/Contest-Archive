//https://omegaup.com/arena/problem/Awesome-Encryption

#include <cstdio>
#include <iostream> 

using namespace std;

int mess;
int mlist[2005];
char s1[2005], s2[2005];

int main()
{
	while(true)
	{
		scanf("%d", &mess);
		if(!mess)
			break;
		for(int i=1; i<=mess; i++)
			scanf("%x", &mlist[i]);
		scanf("%s%s", s1+1, s2+1);
		for(int i=1; i<=mess; i++)
		{
			if(s1[i]!='_')
			{
				unsigned char j=(int(s2[i])^mlist[i]);
				printf("%02X ", (int(s1[i])^int(j)));
			}
			else
			{
				printf("%02X ", mlist[i]);
			}
		}
		if(mess)
			printf("\n");
	}
	return 0;
}
