#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int v, d;
    vector<int> l;
} np;

int queries, x, y, totes;
char inp[5];

vector<node> nList;
pair<int, int> m;

int findLeaf(int n, int p)
{
    int r;
    nList[n].d=1;

    for(int i=0; i<nList[n].l.size(); i++)
    {
        if(nList[n].l[i]!=p)
            r=findLeaf(nList[n].l[i], n);
    }

    if(nList[n].l.size()==1)
        return n;
    else
        return r;
}

pair<int, int> getVal(int n, int p)
{
    //p.first is max that uses node, p.second is max that doesn't
    pair<int, int> t=make_pair(nList[n].v, 0), pi;
    for(int i=0; i<nList[n].l.size(); i++)
    {
        if(nList[n].l[i]!=p)
        {
            pi=getVal(nList[n].l[i], n);
            t.second+=max(pi.first, pi.second);
            t.first+=pi.second;
        }
    }
    return t;
}

int main()
{
    scanf("%d", &queries);
    nList.push_back(np);
    for(int i=1; i<=queries; i++)
    {
        scanf("%s", inp);
        if(inp[0]=='A')
        {
            scanf("%d", &np.v);
            nList.push_back(np);
        }
        if(inp[0]=='B')
        {
            scanf("%d%d", &x, &y);
            nList[x].l.push_back(y);
            nList[y].l.push_back(x);
        }
        if(inp[0]=='C')
        {
            scanf("%d", &x);
            m=getVal(findLeaf(x, 0), 0);
            np.v=max(m.first, m.second);
            nList.push_back(np);
        }
    }

    for(int i=1; i<nList.size(); i++)
        if(!nList[i].d)
        {
            if(nList[i].l.empty())
                totes+=nList[i].v;
            else
            {
                m=getVal(findLeaf(i, 0), 0);
                np.v=max(m.first, m.second);
                nList.push_back(np);
            }
        }

    printf("%d\n", totes);
}
