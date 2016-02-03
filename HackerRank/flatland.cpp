#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=100000;

int cities, stations, station, totes;
int lDist[MAXN+5], rDist[MAXN+5];

int main()
{
    scanf("%d%d", &cities, &stations);
    for(int i=0; i<cities; i++)
        lDist[i]=rDist[i]=100000000;
    for(int i=0; i<stations; i++)
    {
        scanf("%d", &station);
        lDist[station]=0;
        rDist[station]=0;
    }

    for(int i=1; i<cities; i++)
        lDist[i]=min(lDist[i], lDist[i-1]+1);
    for(int i=cities-2; i>=0; i--)
        rDist[i]=min(rDist[i], rDist[i+1]+1);
    for(int i=0; i<cities; i++)
        totes=max(totes, min(lDist[i], rDist[i]));

    printf("%d\n", totes);
}
