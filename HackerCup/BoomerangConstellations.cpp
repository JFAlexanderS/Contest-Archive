#include <cstdio>
#include <map>

using namespace std;

const int MAXN=2000;

struct star
{
    int x, y;
};

int stars, cases, totes;

map<int, int> dist;

star sList[MAXN+5];

int calcDist(star i, star j)
{
    int hDist=i.x-j.x;
    int vDist=i.y-j.y;
    return hDist*hDist+vDist*vDist;
}

int main()
{
    scanf("%d", &cases);
    for(int q=1; q<=cases; q++)
    {
        totes=0;
        scanf("%d", &stars);
        for(int i=1; i<=stars; i++)
            scanf("%d%d", &sList[i].x, &sList[i].y);
        for(int i=1; i<=stars; i++)
        {
            dist.clear();
            for(int j=1; j<=stars; j++)
                totes+=dist[calcDist(sList[i], sList[j])]++;
        }
        dist.clear();
        printf("Case #%d: %d\n", q, totes);
    }
}
