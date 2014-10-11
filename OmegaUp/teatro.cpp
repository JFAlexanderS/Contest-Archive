//https://omegaup.com/arena/problem/teatro

#include <cstdio> 
#include <queue>

using namespace std;

int rows, cols, mus, totes=100000005;
int seat[1005][1005], wfr[1005][1005];

struct sinf
{
	int v, p;
};

struct hp
{
	bool operator() (sinf i, sinf j)
	{
		return i.v<j.v;
	}
};

priority_queue<sinf, vector<sinf>, hp> worst, emp;

int main()
{
	scanf("%d%d%d", &rows, &cols, &mus);
	for(int i=1; i<=rows; i++)
	{
		for(int j=1; j<=cols; j++)
		{
			scanf("%d", &seat[i][j]);
		}
	}
	for(int i=1; i<=rows; i++)
	{
		for(int j=1; j<=cols; j++)
		{
			worst.push({seat[i][j], j});
			if(worst.size()<mus)
				continue;
			while(worst.top().p<=j-mus)
				worst.pop();
			wfr[i][j]=worst.top().v;
		}
		worst=emp;
	}
	for(int i=mus; i<=cols; i++)
	{
		for(int j=1; j<=rows; j++)
		{
			worst.push({wfr[j][i], j});
			if(worst.size()<mus)
				continue;
			while(worst.top().p<=j-mus)
				worst.pop();
			if(worst.top().v<totes)
				totes=worst.top().v;
		}
		worst=emp;
	}
	printf("%d\n", totes);
}
