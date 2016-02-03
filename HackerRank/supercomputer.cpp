#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=15;

int totes, rows, cols;
int grid[MAXN+5][MAXN+5];
char inp[MAXN+5];

bool gridTest(int i, int j, int k)
{
    return (grid[i+k][j]=='G' && grid[i-k][j]=='G' && grid[i][j+k]=='G' && grid[i][j-k]=='G');
}

bool intersect(int p1y, int p1x, int p2y, int p2x, int p3y, int p3x, int p4y, int p4x)
{
    if(p3x<=p1x && p4x>=p1x && p1y<=p3y && p2y>=p3y)
        return true;
    return false;
}

int main()
{
    scanf("%d%d", &rows, &cols);
    for(int i=1; i<=rows; i++)
    {
        scanf("%s", inp+1);
        for(int j=1; j<=cols; j++)
            grid[i][j]=inp[j];
    }

    for(int i1=1; i1<=rows; i1++)
        for(int j1=1; j1<=cols; j1++)
            for(int k1=0; k1<MAXN; k1++)
            {
                if(gridTest(i1, j1, k1))
                {
                    for(int i2=1; i2<=rows; i2++)
                        for(int j2=1; j2<=cols; j2++)
                            for(int k2=0; k2<MAXN; k2++)
                            {
                                if(gridTest(i2, j2, k2) && !(j1==j2 && (i1-k1<i2+k2 || i2-k2<i1+k1)) && !intersect(i1-k1, j1, i1+k1, j1, i2, j2-k2, i2, j2+k2) && !intersect(i2-k2, j2, i2+k2, j2, i1, j1-k1, i1, j1+k1) && !(i1==i2 && (j1-k1<j2+k2 || j2-k2<j1+k1)))
                                    totes=max(totes, (k1*4+1)*(k2*4+1));
                                else
                                    break;
                            }
                }
                else
                    break;
            }

    printf("%d\n", totes);
}
