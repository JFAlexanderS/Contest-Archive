//https://omegaup.com/arena/problem/La-Casa-de-Karel

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int points;

struct point
{
    double x, y;
    bool operator < (const point &wat) const
    {
        if(x!=wat.x)
            return x<wat.x;
        return y<wat.y;
    }
} cval;

int cp(point i, point j)
{
    return (i.x*j.y)-(i.y*j.x);
}

point plist[255];
int poke[255][505], dex[255][505], ser[255], next, plaus, dp[255][255], nnext[255][255], totes, mint;

int cpmake(int o, int p, int n)
{
    point i1, j1;
    i1.x=plist[o].x-plist[p].x;
    i1.y=plist[o].y-plist[p].y;
    j1.x=plist[n].x-plist[p].x;
    j1.y=plist[n].y-plist[p].y;
    return cp(i1, j1);
}

bool hp(int i, int j)
{
    return atan2(plist[i].y-cval.y, plist[i].x-cval.x)<atan2(plist[j].y-cval.y, plist[j].x-cval.x);
}

int dper(int p1, int p2, int p3)
{
    if(dp[p2][p3]!=-1)
        return dp[p2][p3];
    if(p3==p1)
        return 2;
    if(plist[p1].y<=plist[p3].y)
        dp[p2][p3]=dper(p1, p3, nnext[p3][p2])+1;
    int mint2=0;
    if(poke[p2][p3]<=2*(points-1))
        mint2=dper(p1, p2, dex[p2][poke[p2][p3]+1]);
    if(mint2>dp[p2][p3])
        dp[p2][p3]=mint2;
    return dp[p2][p3];
}

int main()
{
    scanf("%d", &points);
    for(int i=1; i<=points; i++)
    {
        scanf("%lf%lf", &plist[i].x, &plist[i].y);
    }
    for(int i=1; i<=points; i++)
    {
        cval=plist[i];
        for(int j=1, f=1; j<=points; j++)
        {
            if(plist[j].x!=cval.x || plist[j].y!=cval.y)
                ser[f++]=j;
        }
        sort(ser+1, ser+points, hp);
        for(int j=1, f=1; j<=(points-1)*2; j++, f++)
        {
            dex[i][j]=ser[f];
            if(j<=points-1)
                poke[i][ser[j]]=j;
            if(j==points-1)
                f=0;
        }
    }
    for(int i=1; i<=points; i++)
    {
        for(int j=1; j<=points; j++)
        {
            if(i!=j)
            {
                for(plaus=1; plaus<=points-1 && cpmake(j, i, dex[i][plaus])<0; plaus++){}
                //cout<<plist[i].x<<" "<<plist[i].y<<" "<<plist[j].x<<" "<<plist[j].y<<" "<<plist[dex[i][plaus]].x<<" "<<plist[dex[i][plaus]].y<<" "<<endl<<plaus<<" "<<cpmake(j, i, dex[i][plaus])<<" ";
                for(; plaus<=2*(points-1) && cpmake(j, i, dex[i][plaus])>=0; plaus++){}
                if (plaus>2*(points-1))
                    nnext[i][j]=-1;
                else
                    nnext[i][j]=dex[i][plaus];
                //cout<<nnext[i][j]<<endl;
            }
        }
    }
    for(int i=1; i<=points; i++)
    {
        for(int j=1; j<=points; j++)
        {
            for(int k=1; k<=points; k++)
            {
                dp[j][k]=-1;
            }
        }
        for(int j=1; j<=points; j++)
        {
            if(i!=j)
            {
                if(nnext[j][i]!=-1 && plist[i].y<=plist[j].y )
                    mint=dper(i, j, nnext[j][i]);
                if(mint>totes)
                    totes=mint;
            }
        }
    }
    printf("%d\n", totes);
    return 0;
}

