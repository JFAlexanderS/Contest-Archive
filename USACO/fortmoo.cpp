#include <cstdio>
#include <algorithm>

using namespace std;

#define UPLOAD 1
#if UPLOAD
#define openFiles() freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout)
#else
#define openFiles()
#endif

const int MAXN=200;

int rows, cols, totes;
int fort[MAXN+5][MAXN+5], cSum[MAXN+5][MAXN+5];
char inp[MAXN+5];

int main()
{
    openFiles();
    scanf("%d%d", &rows, &cols);
    for(int i=1; i<=rows; i++)
    {
        scanf("%s", inp+1);
        for(int j=1; j<=cols; j++)
        {
            fort[i][j]=inp[j];
            if(fort[i][j]=='.')
                totes=1;
            cSum[i][j]=cSum[i-1][j]+(fort[i][j]=='X');
        }
    }
    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=cols; j++)
        {
            if(fort[i][j]=='.')
            {
                for(int k=i+1; k<=rows; k++)
                {
                    if(fort[k][j]=='.')
                    {
                        for(int l=j+1; l<=cols; l++)
                        {
                            if(fort[i][l]=='.' && fort[k][l]=='.')
                            {
                                if(cSum[i-1][l]==cSum[k][l])
                                    totes=max(totes, (k-i+1)*(l-j+1));
                            }
                            else
                                break;
                        }
                    }
                    else
                        break;
                }
            }
        }
    }

    printf("%d\n", totes);
}
