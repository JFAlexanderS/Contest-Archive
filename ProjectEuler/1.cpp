#include <cstdio>

int totes;

int main()
{
    for(int i=1; i<1000; i++)
        if(i%3==0 || i%5==0)
            totes+=i;

    printf("%d\n", totes);
}
