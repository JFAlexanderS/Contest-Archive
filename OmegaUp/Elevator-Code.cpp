//https://omegaup.com/arena/problem/Elevator-Code#

#include <cstdio>

using namespace std; 

int cases, end, biggest, cons, totes; 
int n[25], d[25], p[25], pos[25], neg[25];

char code[505], digis[505];

int main()
{
	p[1]=1;
	p[2]=10;
	p[3]=100;
	p[4]=1000;
	p[5]=10000;
	p[6]=100000;
	p[7]=1000000;
	scanf("%d", &cases);
	for(int q=1; q<=cases; q++)
	{
		scanf("%s", code+1);
		code[0]='+';
		scanf("%s", digis);
		for(int i=0; i<=9; i++)
			d[i]=0, pos[i]=0, neg[i]=0;
		for(int i=0; digis[i]; i++)
			d[digis[i]-'0']++;
		for(int i=0; code[i]; i++)
			end=i;
		for(int i=end; i>=0; i--)
		{
			if(code[i]=='+')
			{
				while(cons)
				{
					pos[cons]++;
					cons--;
				}
			}
			else if(code[i]=='-')
			{
				while(cons)
				{
					neg[cons]++;
					cons--;
				}
			}
			else
				cons++;
		}
		totes=0;
		biggest=9;
		for(int i=7; i; i--)
		{
			while(pos[i])
			{
				while(!d[biggest])
					biggest--;
				totes+=p[i]*biggest;
				d[biggest]--;
				pos[i]--;
			}
		}
		for(int i=1; i<=7; i++)
		{
			while(neg[i])
			{
				while(!d[biggest])
					biggest--;
				totes-=p[i]*biggest;
				d[biggest]--;
				neg[i]--;
			}
		}
		printf("%d\n", totes);
	}
	return 0;
}
