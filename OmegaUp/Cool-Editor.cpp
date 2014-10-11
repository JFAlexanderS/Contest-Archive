//https://omegaup.com/arena/problem/Cool-Editor#

#include <cstdio>
#include <string>
#include <vector>  

using namespace std;

int mind, totes=1000000, mkill, words;
int dead[1005], curlen[1005];
char inp[1005];

vector<string> slist(1005);

int main()
{
	scanf("%d", &words);
	for(int i=1; i<=words; i++)
	{
		scanf("%s", inp);
		slist[i]=inp;
		if(slist[i].size()>slist[mind].size())
		{
			mind=i;
		}
		curlen[i]=slist[i].size();
	}
	for(int i=0; i<slist[mind].size(); i++)
	{
		mkill=0;
		for(int j=1; j<=words; j++)
		{
			if(!dead[j] && slist[mind][i]==slist[j][i])
				curlen[j]--;
			else
				curlen[j]++, dead[j]=1;
			if(curlen[j]>mkill)
				mkill=curlen[j];
		}
		if(mkill<totes)
			totes=mkill;
	}
	printf("%d\n", totes); 
	return 0;
}
