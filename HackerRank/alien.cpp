#include <cstdio>

using namespace std;

const long long P=1000000007;
long long totes, t1, t2;

long long powe(long long a, long long p)
{
    if(p==1)
        return a;
    else
    {
        long long t=powe(a, p/2);
        t*=t;
        t%=P;
        if(p%2)
            t*=a;
        t%=P;
        return t;
    }
}

long long factorial(long long n)
{
    long long f=1;
    for(long long i=1; i<=n; i++)
        f=(f*i)%P;
    return f;
}

long long ch(long long n, long long k)
{
    long long nf=factorial(n), kf=factorial(k), nkf=factorial(n-k);
    kf*=nkf;
    kf%=P;
    kf=powe(kf, P-2);
    return (nf*kf)%P;
}

long long A, B, C, D;

int main()
{
    scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
    if(B!=D && B-D!=-1 && B-D!=1)
    {
        printf("0\n");
        return 0;
    }
    if(B==0 && D==0 && A>0 && C>0)
    {
        printf("0\n");
        return 0;
    }
    if(B==0 && D==0 && (A>0 || C>0))
    {
        printf("%lld\n", 1);
        return 0;
    }

    if(B>D)
    {
        t1=ch(B+A-1, A);
        t2=ch(B+C-1, C);
        totes=(t1*t2)%P;
    }
    else if(D>B)
    {
        t1=ch(D+A-1, A);
        t2=ch(D+C-1, C);
        totes=(t1*t2)%P;

    }
    else
    {
        t1=ch(B+A, A);
        t2=ch(D+C-1, C);
        totes=(t1*t2)%P;

        t1=ch(D+A-1, A);
        t2=ch(B+C, C);
        totes+=(t1*t2)%P;
        totes%=P;

    }
    printf("%lld\n", totes);
}
