/*
 ID: spleens2
 PROG: combo
 LANG: C++
*/

#define UPLOAD 1
#if UPLOAD
#define openFiles() freopen("combo.in", "r", stdin); freopen("combo.out", "w", stdout)
#else
#define openFiles()
#endif

#include <cstdio>
#include <cmath>

using namespace std;

int N, totes, c1[5], c2[5], c3[5];

bool twoDist(int i, int j)
{
    return (fabs(i-j)<=2 || fabs((i+N)-j)<=2 || fabs(i-(j+N))<=2);
}

int main()
{
    openFiles();
    scanf("%d", &N);
    for(int i=1; i<=3; i++)
        scanf("%d", &c1[i]);
    for(int i=1; i<=3; i++)
        scanf("%d", &c2[i]);

    for(c3[1]=1; c3[1]<=N; c3[1]++)
        for(c3[2]=1; c3[2]<=N; c3[2]++)
            for(c3[3]=1; c3[3]<=N; c3[3]++)
            {
                bool farmer=true, master=true;
                for(int i=1; i<=3; i++)
                    farmer&=twoDist(c1[i], c3[i]), master&=twoDist(c2[i], c3[i]);
                if(farmer || master)
                    totes++;
            }

    printf("%d\n", totes);
}
