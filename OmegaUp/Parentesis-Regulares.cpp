#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN=1000000;

char inp[MAXN+5];
int sz, totes, res;
int sta[MAXN+5];

int getVal(char c)
{
    if(c=='(')
        return -1;
    else if(c==')')
        return -2;
}

int main()
{
    scanf("%s", inp+1);
    for(int i=1; inp[i]; i++)
    {
        int v=getVal(inp[i]);
        if(!sz || (sta[sz]>0 && sz-1==0))
            sta[++sz]=v;
        else if(v==-1)
            sta[++sz]=v;
        else
        {
            if(sta[sz]==-2)
                sta[++sz]=v;
            else
            {
                if(sta[sz]==-1)
                {
                    sta[sz]=2;
                    while(sta[sz-1]>0)
                    {
                        sta[sz-1]+=sta[sz];
                        sz--;
                    }
                }
                else
                {
                    if(sta[sz-1]==0 || sta[sz-1]==-2)
                        sta[++sz]=v;
                    else
                    {
                        sta[sz-1]=sta[sz]+2;
                        sz--;
                        while(sta[sz-1]>0)
                        {
                            sta[sz-1]+=sta[sz];
                            sz--;
                        }
                    }
                }
            }
        }
    }
    
    for(int i=1; i<=sz; i++)
    {
        if(sta[i]>totes)
            totes=sta[i], res=1;
        else if(sta[i]==totes)
            res++;
    }
    
    if(!totes)
        printf("0 1\n");
    else
        printf("%d %d\n", totes, res);
    return 0;
}
