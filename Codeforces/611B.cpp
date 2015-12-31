#include <cstdio>
#include <iostream>

using namespace std;

unsigned long long a, b, ONE=1, totes;

int main()
{
    cin>>a>>b;
    for(long long i=1; i<64; i++)
        for(long long j=0; j<i-1; j++)
            if((((ONE<<i)-ONE)^(ONE<<j))>=a && (((ONE<<i)-ONE)^(ONE<<j))<=b)
                totes++;
    cout<<totes<<endl;
}
