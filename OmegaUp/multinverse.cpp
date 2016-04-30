#include <cstdio>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b, long long &x, long long &y)
{
        //ax+by=gcd(a, b)
        if(b==0)
        {
                x=1;
                y=0;
                return a;
        }
        long long m=a/b, r=a%b, u, v, g;
        g=gcd(b, r, u, v);
        x=v;
        y=u-(m*v);
        return g;
}


int main()
{
    long long x, y, a, b;
    //ax+by=gcd(a, b);
    //ax=1 mod n
    //ax-by=1
    cin>>a>>b;
    if(gcd(a, b, x, y)!=1)
    {
        printf("-1\n");
    }
    else
    {
        while (x<0)
        {
            x+=b;
        }
        cout<<x%b<<"\n";
    }
    return 0;
}
