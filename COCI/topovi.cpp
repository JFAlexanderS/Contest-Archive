#include <cstdio>
#include <map>

using namespace std;

const long long MAXR=100000;

struct rook
{
    long long r, c, p;
};

long long rooks, queries, dim, totes;

map<long long, long long> rowQuant, colQuant, rowVal, colVal;
map<pair<long long, long long>, long long> power;

rook rList[MAXR+5], prv[MAXR+5], nxt[MAXR+5];

long long rowQuery(long long r)
{
    return dim-colQuant[rowVal[r]];
}

long long colQuery(long long c)
{
    return dim-rowQuant[colVal[c]];
}

void putRook(long long r, long long c, long long p)
{
    totes-=rowQuery(r);
    totes-=colQuery(c);
    totes+=((rowVal[r]^colVal[c])!=0);

    rowQuant[rowVal[r]]--;
    colQuant[colVal[c]]--;

    rowVal[r]^=p;
    colVal[c]^=p;

    rowQuant[rowVal[r]]++;
    colQuant[colVal[c]]++;

    totes+=rowQuery(r);
    totes+=colQuery(c);
    totes-=((rowVal[r]^colVal[c])!=0);
}

int main()
{
    scanf("%lld%lld%lld", &dim, &rooks, &queries);
    for(long long i=1; i<=rooks; i++)
        scanf("%lld%lld%lld", &rList[i].r, &rList[i].c, &rList[i].p);
    for(long long i=1; i<=queries; i++)
        scanf("%lld%lld%lld%lld", &prv[i].r, &prv[i].c, &nxt[i].r, &nxt[i].c);
    rowQuant[0]=dim, colQuant[0]=dim;

    for(long long i=1; i<=rooks; i++)
    {
        power[make_pair(rList[i].r, rList[i].c)]=rList[i].p;
        putRook(rList[i].r, rList[i].c, rList[i].p);
    }

    for(long long i=1; i<=queries; i++)
    {
        putRook(prv[i].r, prv[i].c, power[make_pair(prv[i].r, prv[i].c)]);
        putRook(nxt[i].r, nxt[i].c, power[make_pair(prv[i].r, prv[i].c)]);
        power[make_pair(nxt[i].r, nxt[i].c)]=power[make_pair(prv[i].r, prv[i].c)];
        printf("%lld\n", totes);
    }
}
