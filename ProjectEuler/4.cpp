#include <cstdio>
#include <string>

using namespace std;

int totes=0;

bool palindromic(int n)
{
    string s1=to_string(n), s2;
    s2=s1;
    reverse(s1.begin(), s1.end());
    return s1==s2;
}

int main()
{
    for(int i=100; i<=999; i++)
        for(int j=100; j<=999; j++)
            if(palindromic(i*j) && i*j>totes)
                totes=i*j;
    printf("%d\n", totes);
}
