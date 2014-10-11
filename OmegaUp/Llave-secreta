//https://omegaup.com/arena/problem/Llave-secreta#/show-run

#include <cstdio>

using namespace std;

int rows, cols, imag, ri, ci;
int mapa[25][25], ilist[25][25][25];
int kit;

int main()
{
	scanf("%d%d", &rows, &cols);
	scanf("%d", &imag);
	for(int i=1; i<=rows; i++)
	{
		for(int j=1; j<=cols; j++)
		{
			scanf("%d", &mapa[i][j]);
		}
	}
	for(int q=1; q<=imag; q++)
	{
		scanf("%d%d", &ri, &ci);
		for(int i=1; i<=ri; i++)
		{
			for(int j=1; j<=ci; j++)
			{
				scanf("%d", &ilist[q][i][j]);
			}
		}
		for(int i=1; i<=rows; i++)
		{
			for(int j=1; j<=cols; j++)
			{
				kit=0;
				for(int k=1, ic=i; k<=ri && ic<=rows ; k++, ic++)
				{
					for(int l=1, jc=j; l<=ci && jc<=cols ; l++, jc++)
					{
						if(ilist[q][k][l]==mapa[ic][jc])
							kit++;
						else
							k=ri+1, l=ci+1;
					}
				}
				if(kit==ri*ci)
				{
					printf("%d\n", q);
					printf("%d %d\n", i, j);
					return 0;
				}
			}
		}
	}	
	printf("-1\n");	
}
