//https://omegaup.com/arena/problem/Andar-Chido

#include <cstdio>
#include <iostream>

using namespace std;

struct state
{
    char x1, y1, x2, y2, x3, y3;
} ini, fin, n;

int cols, rows, friends, qf, qb;
int vised[18][18][18][18][18][18];
char guan[20][20], inp[20], mvs[10][5];

state queue[50000000];

bool pcomp(int x1, int x2, int y1, int y2)
{
    if(x1==0 || x2==0)
        return false;
    if(x1==x2 && y1==y2)
        return true;
    return false;
}

int main()
{
    mvs[1][1]=0;
    mvs[1][2]=-1;
    mvs[2][1]=1;
    mvs[2][2]=0;
    mvs[3][1]=0;
    mvs[3][2]=1;
    mvs[4][1]=-1;
    mvs[4][2]=0;
    for(int i=0; i<=rows+1; i++)
    {
        for(int j=0; j<=cols+1; j++)
        {
            guan[j][i]='#';
        }
    }
    //N=1, E=2, S=3, W=4
    scanf("%d%d%d", &cols, &rows, &friends);
    for(int i=1; i<=rows; i++)
    {
        scanf("%s", inp+1);
        for(int j=1; j<=cols; j++)
        {
            guan[j][i]=inp[j];
            if(guan[j][i]=='a')
            {
                ini.x1=j;
                ini.y1=i;
            }
            if(guan[j][i]=='b')
            {
                ini.x2=j;
                ini.y2=i;
            }
            if(guan[j][i]=='c')
            {
                ini.x3=j;
                ini.y3=i;
            }
            if(guan[j][i]=='A')
            {
                fin.x1=j;
                fin.y1=i;
            }
            if(guan[j][i]=='B')
            {
                fin.x2=j;
                fin.y2=i;
            }
            if(guan[j][i]=='C')
            {
                fin.x3=j;
                fin.y3=i;
            }
        }
    }
    //2 1 1
    //Aa
    qf=1;
    qb=1;
    queue[qf]=ini;
    qb++;
    vised[ini.x1][ini.y1][ini.x2][ini.y2][ini.x3][ini.y3]=1;
    guan[0][0]='.';
    for(; !vised[fin.x1][fin.y1][fin.x2][fin.y2][fin.x3][fin.y3]; qf++)
    {
        n=queue[qf];
        for(int i=1; i<=5; i++)
        {
            if(n.x1==0)
                i=5;
            if(guan[n.x1+mvs[i][1]][n.y1+mvs[i][2]]=='#')
                continue;
            for(int j=1; j<=5; j++)
            {
                if(n.x2==0)
                    j=5;
                if((guan[n.x2+mvs[j][1]][n.y2+mvs[j][2]]=='#') || pcomp(n.x1+mvs[i][1], n.x2+mvs[j][1], n.y1+mvs[i][2], n.y2+mvs[j][2]) || (pcomp(n.x1, n.x2+mvs[j][1], n.y1, n.y2+mvs[j][2]) && pcomp(n.x2, n.x1+mvs[i][1], n.y2, n.y1+mvs[i][2])))
                    continue;
                for(int k=1; k<=5; k++)
                {
                    if(n.x3==0)
                        k=5;
                    //Still need second comparison here
                    if((n.x3!=0 && guan[n.x3+mvs[k][1]][n.y3+mvs[k][2]]=='#') || pcomp(n.x1+mvs[i][1], n.x3+mvs[k][1], n.y1+mvs[i][2], n.y3+mvs[k][2]) || pcomp(n.x3+mvs[k][1], n.x2+mvs[j][1], n.y3+mvs[k][2], n.y2+mvs[j][2]) || (pcomp(n.x1, n.x3+mvs[k][1], n.y1, n.y3+mvs[k][2]) && pcomp(n.x3, n.x1+mvs[i][1], n.y3, n.y1+mvs[i][2])) || (pcomp(n.x3, n.x2+mvs[j][1], n.y3, n.y2+mvs[j][2]) && pcomp(n.x2, n.x3+mvs[k][1], n.y2, n.y3+mvs[k][2])))
                        continue;
                    if(!vised[n.x1+mvs[i][1]][n.y1+mvs[i][2]][n.x2+mvs[j][1]][n.y2+mvs[j][2]][n.x3+mvs[k][1]][n.y3+mvs[k][2]])
                    {
                        queue[qb].x1=n.x1+mvs[i][1];
                        queue[qb].y1=n.y1+mvs[i][2];
                        queue[qb].x2=n.x2+mvs[j][1];
                        queue[qb].y2=n.y2+mvs[j][2];
                        queue[qb].x3=n.x3+mvs[k][1];
                        queue[qb].y3=n.y3+mvs[k][2];
                        vised[n.x1+mvs[i][1]][n.y1+mvs[i][2]][n.x2+mvs[j][1]][n.y2+mvs[j][2]][n.x3+mvs[k][1]][n.y3+mvs[k][2]]=vised[n.x1][n.y1][n.x2][n.y2][n.x3][n.y3]+1;
                        qb++;
                    }
                }
            }
        }
    }
    printf("%d\n", vised[fin.x1][fin.y1][fin.x2][fin.y2][fin.x3][fin.y3]-1);
    return 0;
}

