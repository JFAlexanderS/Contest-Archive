//https://omegaup.com/arena/problem/Dr-Ethan-Freud

#include <iostream>
#include <cstdio>

using namespace std;

int choco, w4, w2, chsave;

int main()
{
    scanf("%d", &choco);
    chsave=choco;
    for(int i=1; true; i+=2)
    {
        if(i==1)
        {
            if(choco==1)
            {
                printf("1\n");
                return 0;
            }
            continue;
        }
        choco=chsave;
        if(choco%2)
        {
            choco--;
            w2=(i-1)/2;
            w2=(w2-1)/2+((w2-1)%2);
            w2*=4;
            if(choco%4==2)
            {
                if(w2>=2)
                {
                    w2-=2;
                    choco-=2;
                }
            }
            w4=i/2;
            if(w4%2)
            {
                w4=(w4*w4)/2+1;
            }
            else
            {
                w4=(w4*w4)/2;
            }
            w4*=4;
            if(w4+w2>=choco && choco%4==0)
                choco=0;
        }
        else
        {
            w2=(i-1)/2;
            w2=w2/2+w2%2;
            w2*=4;
            if(choco%4==2)
            {
                if(w2>=2)
                {
                    w2-=2;
                    choco-=2;
                }
                if(i==3)
                {
                    if(w2>=choco)
                    {
                        printf("%d\n", i);
                        return 0;
                    }
                    else
                        continue;
                }
            }
            else
                if(i==3)
                    w2=0;
            w4=i/2;
            if(w4%2)
            {
                w4=(w4*w4)/2;
            }
            else
            {
                w4=(w4*w4)/2;
            }
            w4*=4;
            if(w4+w2>=choco && choco%4==0)
                choco=0;
        }
        if(!choco)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
