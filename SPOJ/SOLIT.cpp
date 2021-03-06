//http://www.spoj.com/problems/SOLIT/

#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <cstdlib>
using namespace std;
struct pos
{
    unsigned long long s;
    int d;
    int f;
} ps, mpa;
struct cd
{
    int c, d;
} incd;
map<unsigned long long, cd> vis;
queue<pos> el;
int ex, wy, cases, q, mvcmp;
int movs[4];
unsigned long long one=1, kitcmp;
bool m(int bitnum, unsigned long long ate, int md, pos la)
{unsigned long long dope;
    for(int i=0; i<4; i++)
    {
        //modify for visited
        if(bitnum+movs[i]>=0 && bitnum+movs[i]<=63 && ((md+movs[i]>=0 && md+movs[i]<=7) || (movs[i]<-1 || movs[i]>1)))
        {
            kitcmp=ate|(one<<(movs[i]+bitnum));
            if(kitcmp==ate)
            {
                kitcmp=ate|(one<<((movs[i]*2)+bitnum));
                mvcmp=movs[i]*2;
                if(kitcmp!=ate && bitnum+mvcmp>=0 && bitnum+mvcmp<=63 && ((md+mvcmp>=0 && md+mvcmp<=7) || (movs[i]<-1 || movs[i]>1)))
                {
                    dope=ate;
                    dope^=one<<bitnum;
                    dope|=one<<(bitnum+mvcmp);
                    //cout<<dope<<endl;
                    //system("PAUSE");
                    mpa.s=dope;
                    mpa.d=la.d+1;
                    mpa.f=la.f;
                    if(vis[mpa.s].c==q && vis[mpa.s].d!=mpa.f)
                    {
                        return true;
                    }
                    else
                    {
                        if(vis[mpa.s].c!=q)
                        {
                            vis[mpa.s].c=q;
                            vis[mpa.s].d=mpa.f;
                            el.push(mpa);
                        }
                    }
                }
            }
            else
            {
                dope=ate;
                dope^=one<<bitnum;
                dope|=one<<(bitnum+movs[i]);
                //cout<<dope<<endl;
                //system("PAUSE");
                mpa.s=dope;
                mpa.d=la.d+1;
                mpa.f=la.f;
                if(vis[mpa.s].c==q && vis[mpa.s].d!=mpa.f)
                {
                    return true;
                }
                else
                {
                    if(vis[mpa.s].c!=q)
                    {
                        vis[mpa.s].c=q;
                        vis[mpa.s].d=mpa.f;
                        el.push(mpa);
                    }
                }
            }
        }
    }
    return false;
}
bool app()
{
    while(el.front().d!=4)
    {
        ps=el.front();
        //cout<<ps.s<<endl;
        for(int i=0; i<64; i++)
        {
            kitcmp=((one<<i)|ps.s);
            if(kitcmp==ps.s)
            {
                if(m(i, ps.s, i%8, ps))
                {
                    return true;
                }
            }
        }
        el.pop();
    }
    return false;
}
int main()
{
    movs[0]=1;
    movs[1]=-1;
    movs[2]=8;
    movs[3]=-8;
    scanf("%d", &cases);
    for(q=1; q<=cases; q++)
    {
        ps.s=0;
        ps.d=0;
        ps.f=1;
        for(int i=1; i<=4; i++)
        {
            scanf("%d%d", &wy, &ex);
            ps.s|=one<<((ex-1)+(8*(wy-1)));
        }
        el.push(ps);
        ps.s=0;
        for(int i=1; i<=4; i++)
        {
            scanf("%d%d", &wy, &ex);
            ps.s|=one<<((ex-1)+(8*(wy-1)));
        }
        ps.f=-1;
        el.push(ps);
        //cout<<ps.s<<endl;
        //system("PAUSE");
        ps.s=0;
        if(app())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        while(!el.empty())
        {
            el.pop();
        }
    }
    return 0;
}

