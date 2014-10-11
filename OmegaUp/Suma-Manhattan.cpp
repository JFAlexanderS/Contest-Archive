//https://omegaup.com/arena/problem/Suma-Manhattan

#include <cstdio> 
#include <algorithm> 

using namespace std; 

const long long MOD=1000000007;
long long points, xg, yg, xs, ys, totes; 
long long xl[500005], yl[500005];

int main()
{
	scanf("%lld", &points);
	for(int i=1; i<=points; i++)
	{
		scanf("%lld%lld", &xl[i], &yl[i]);
		xg+=xl[i];
		yg+=yl[i];
	}
	sort(xl+1, xl+1+points);
	sort(yl+1, yl+1+points);
	for(int i=1, j=0; i<=points; i++, j++)
	{
		totes+=(xg-(xl[i]*(points-j)));
		totes%=MOD;
		xg-=xl[i];
		xs+=xl[i];
		totes+=(yg-(yl[i]*(points-j)));
		totes%=MOD;
		yg-=yl[i];
		ys+=yl[i];
	}
	printf("%lld\n", totes);
	return 0; 
}
