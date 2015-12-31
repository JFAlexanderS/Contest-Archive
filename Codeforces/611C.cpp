#include <cstdio>

using namespace std;

const int MAXN=500;

int height, width, queries, r1, r2, c1, c2, totes;
int horz[MAXN+5][MAXN+5], vert[MAXN+5][MAXN+5], minh[MAXN+5], minv[MAXN+5];
char domino[MAXN+5][MAXN+5];

int main()
{
    scanf("%d%d", &height, &width);
    for(int i=1; i<=height; i++)
        scanf("%s", domino[i]+1);

    for(int i=1; i<=height; i++)
        for(int j=2; j<=width; j++)
        {
            minh[j]=minh[j-1]+(domino[i][j]=='.' && domino[i][j-1]=='.');
            horz[i][j]=horz[i-1][j]+minh[j];
        }

    for(int i=1; i<=width; i++)
        for(int j=2; j<=height; j++)
        {
            minv[j]=minv[j-1]+(domino[j][i]=='.' && domino[j-1][i]=='.');
            vert[j][i]=vert[j][i-1]+minv[j];
        }

    scanf("%d", &queries);
    for(int i=1; i<=queries; i++)
    {
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        totes=0;
        r1++;
        totes+=vert[r2][c2]-vert[r2][c1-1]-vert[r1-1][c2]+vert[r1-1][c1-1];
        r1--;
        c1++;
        totes+=horz[r2][c2]-horz[r2][c1-1]-horz[r1-1][c2]+horz[r1-1][c1-1];
        c1--;
        printf("%d\n", totes);
    }
}
