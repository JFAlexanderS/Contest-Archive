//https://www.facebook.com/hackercup/problems.php?pid=1036037553088752&round=742632349177460

#include <cstdio>

using namespace std;

struct food
{
	int p, c, f;
};
	
int cases, foods, psum, pgoal, csum, cgoal, fsum, fgoal;
bool plaus;

food flist[25];

void dfs(int n)
{
	if(n>foods)
	{
		if(psum==pgoal && csum==cgoal && fsum==fgoal)
			plaus=true;
		return; 
	}
	dfs(n+1);
	psum+=flist[n].p;
	csum+=flist[n].c;
	fsum+=flist[n].f;
	dfs(n+1);
	psum-=flist[n].p;
	csum-=flist[n].c;
	fsum-=flist[n].f;
}

int main()
{
	scanf("%d", &cases);
	for(int q=1; q<=cases; q++)
	{
		plaus=false;
		scanf("%d%d%d", &pgoal, &cgoal, &fgoal);
		scanf("%d", &foods);
		for(int i=1; i<=foods; i++)
			scanf("%d%d%d", &flist[i].p, &flist[i].c, &flist[i].f);
		dfs(1);
		if(plaus)
			printf("Case #%d: yes\n", q);
		else
			printf("Case #%d: no\n", q);
	}
}
