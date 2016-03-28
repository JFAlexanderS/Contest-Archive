#include <cstdio>
#include <string>

using namespace std;

const int MAXN=2000000;

int len, notLeft, notMid, notRight, lSkip, rSkip, nextV, notUnique;
char word[MAXN+5], pass[MAXN+5];

string s[5], c;

void print(int l, int r)
{
	for(int i=l, j=0; i<=r; i++, j++)
		pass[j]=word[i];
	pass[r+1]=0;
	c=pass;
	for(int k=0; k<nextV; k++)
		if(s[k]==c)
			return;
	s[nextV++]=c;
}

int main()
{
	scanf("%d", &len);
	scanf("%s", word+1);
	if(!(len%2))
	{
		printf("NOT POSSIBLE\n");
		return 0;
	}
	//Middle
	for(int i=1, j=(len+1)/2+1; j<=len; i++, j++)
		if(word[i]!=word[j])
			notMid=1;
	//Left
	for(int i=1, j=(len+1)/2+1; j<=len; i++, j++)
	{
		if(word[i]!=word[j])
			lSkip++, j--;
		if(lSkip==2)
		{
			notLeft=1;
			break;
		}
	}
	//Right
	for(int i=1, j=(len+1)/2; j<=len; i++, j++)
	{
		if(word[i]!=word[j])
			rSkip++, i--;
		if(rSkip==2)
		{
			notRight=1;
			break;
		}
	}
	//Output
	if(notMid+notRight+notLeft>2)
		printf("NOT POSSIBLE\n");

	if(!notMid)
		print(1, len/2);
	if(!notLeft)
		print(len/2+2, len); 
	if(!notRight)
		print(1, len/2);
	
	if(nextV>1)
		printf("NOT UNIQUE\n");
	else
	{
		for(int i=0; i<s[0].size(); i++)
			printf("%c", s[0][i]);
		printf("\n");
	}
		
}
