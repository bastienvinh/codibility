#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A)
{
    
    unordered_map<int, bool> countLetters;
    int result = -1;
    
    for (int i = 0; i < A.size(); ++i)
    {
        int value = A[i];
        unordered_map<int, bool>::iterator it = countLetters.find(value);
        
        if (it != countLetters.end())
            countLetters.erase(it);
        else
            countLetters[value] = true;
    }
    
    if (countLetters.size() > 0)
    {
        unordered_map<int,bool>::iterator it = countLetters.begin();
        result = it->first;
    }
    
    return result;
}
