//https://omegaup.com/arena/problem/Zorro

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct point
{
    double x, y;
};

struct path
{
    double len;
    int h1, h2;
};

int paths, s1, s2, totes, points;
int uph[2005], apply[2005];
double notyet[2005];
double hd, vd;

point plist[2005];
path dlist[4000005];

bool hp(path i, path j)
{
    return i.len>j.len;
}

int main()
{
    scanf("%d", &points);
    for(int i=1; i<=points; i++)
        scanf("%lf%lf", &plist[i].x, &plist[i].y);
    for(int i=0; i<=points; i++)
    {
        for(int j=i+1; j<=points; j++)
        {
            paths++;
            hd=plist[i].x-plist[j].x;
            hd*=hd;
            vd=plist[i].y-plist[j].y;
            vd*=vd;
            dlist[paths].len=sqrt(hd+vd);
            dlist[paths].h1=i;
            dlist[paths].h2=j;
        }
    }
    sort(dlist, dlist+1+paths, hp);
    for(int i=0; i<=paths; i++)
    {
        if(notyet[dlist[i].h1]>dlist[i].len && apply[dlist[i].h1])
        {
            uph[dlist[i].h1]=apply[dlist[i].h1];
            apply[dlist[i].h1]=0;
        }
        if(notyet[dlist[i].h2]>dlist[i].len && apply[dlist[i].h2])
        {
            uph[dlist[i].h2]=apply[dlist[i].h2];
            apply[dlist[i].h2]=0;
        }
        s1=uph[dlist[i].h1];
        s2=uph[dlist[i].h2];
        if(s1+1>uph[dlist[i].h2] && s1+1>apply[dlist[i].h2] && (s1 || (dlist[i].h1==0 && !s1)) && dlist[i].h2!=0)
        {
            apply[dlist[i].h2]=s1+1;
            notyet[dlist[i].h2]=dlist[i].len;
        }
        if(s2+1>uph[dlist[i].h1] && s2+1>apply[dlist[i].h1] && (s2 || (dlist[i].h2==0 && !s2)) && dlist[i].h1!=0)
        {
            apply[dlist[i].h1]=s2+1;
            notyet[dlist[i].h1]=dlist[i].len;
        }
        if(uph[dlist[i].h2]>totes)
            totes=uph[dlist[i].h2];
        if(uph[dlist[i].h1]>totes)
            totes=uph[dlist[i].h1];
        if(apply[dlist[i].h2]>totes)
            totes=apply[dlist[i].h2];
        if(apply[dlist[i].h1]>totes)
            totes=apply[dlist[i].h1];
    }
    printf("%d\n", totes);
    return 0;
}
