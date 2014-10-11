//https://omegaup.com/arena/problem/Feria-con-Juegos

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

long long sq, games, queries, val, opt, plaus, totes, gn, nval;
long long oall[2005], perq[2005][25], cop[2005];
char inp[105];

vector<long long> glist[2005];

void calculate()
{
    for(int i=0; i<glist[games].size(); i++)
    {
        perq[games][i]=0;
        for(int j=1; j<=games; j+=glist[games][i])
        {
            perq[games][i]+=oall[j];
        }
    }
}

int main()
{
    cop[1]=1;
    cop[2]=1;
    cop[3]=1;
    cop[4]=1;
    cop[6]=1;
    for(int i=1; i<=2005; i++)
    {
        sq=sqrt(i);
        if(!cop[i])
            glist[i].push_back(1);
        for(int j=2; j<=sq; j++)
        {
            if(i%j==0)
            {
                glist[i].push_back(j);
                if(i!=sq)
                    glist[i].push_back(i/j);
            }
        }
    }
    scanf("%lld%lld", &games, &queries);
    for(int i=1; i<=games; i++)
    {
        scanf("%lld", &val);
        oall[i]+=val;
    }
    calculate();
    for(int i=1; i<=queries; i++)
    {
        scanf("%s", inp+1);
        if(inp[1]=='T')
        {
            scanf("%lld", &games);
            opt=1;
        }
        else if(inp[1]=='J')
        {
            if(opt)
                calculate(), opt=0;
            totes=oall[1];
            for(int i=0; i<glist[games].size() && games>2; i++)
            {
                if(perq[games][i]>totes)
                    totes=perq[games][i];
            }
            printf("%lld\n", totes);
        }
        else if(inp[1]=='C')
        {
            if(opt)
                calculate(), opt=0;
            scanf("%lld%lld", &gn, &nval);
            for(int i=0; i<glist[games].size(); i++)
            {
                if(gn%glist[games][i]==1%glist[games][i])
                    perq[games][i]-=oall[gn];
            }
            oall[gn]=nval;
            for(int i=0; i<glist[games].size(); i++)
            {
                if(gn%glist[games][i]==1%glist[games][i])
                    perq[games][i]+=nval;
            }
        }
    }
    return 0;
}
