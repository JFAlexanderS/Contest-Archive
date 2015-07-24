#include <cstdio>

int totes;

int main()
{
    for(int i1=0, i2=1; i2<=4000000; )
    {
        if(i2%2==0)
            totes+=i2;
        i2+=i1;
        i1=i2-i1;
    }
    printf("%d\n", totes);
}
