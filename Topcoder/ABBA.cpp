#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class ABBA
{
    public: string canObtain(string initial, string target)
    {
        while(target.length()!=initial.length())
        {
            if(target[target.length()-1]=='A')
                target.pop_back();
            else
            {
                target.pop_back();
                reverse(target.begin(), target.end());
            }
        }
        if(target==initial)
            return "Possible";
        else
            return "Impossible";
    }
};
