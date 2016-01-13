#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int maxim;

class AttackOfTheClones
{
    public: int count(vector<int> firstWeek, vector<int> lastWeek)
    {
        for(int i=0; i<firstWeek.size(); i++)
            for(int j=0; j<i; j++)
                if(firstWeek[i]==lastWeek[j])
                    maxim=max(maxim, i-j);
        return maxim+1;
    }
};
