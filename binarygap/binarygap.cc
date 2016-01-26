
// Link : https://codility.com/demo/take-sample-test/binary_gap/


#include <algorithm>
#include <iostream>
#include <list>
#include <iterator>
#include <cmath>

using namespace std;

list<bool> GetBitNumber(unsigned int number);
void testTabint(list<bool> tab);
int GetMaxIndice(unsigned int number);
int CountMax( list<bool> tab );


struct TagPassage {
    int previous;
    int count;
    int max;
};

TagPassage Create();
void ResetTag( TagPassage * tag );

int solution(int N) {
    list<bool> result = GetBitNumber(N);
    return CountMax(result);
}

void testTabint(list<bool> tab)
{
    for (list<bool>::iterator it = tab.begin(); it != tab.end(); ++it)
        cout << *it;
    
    cout << endl;
}


TagPassage Create(  )
{
    TagPassage newOne;
    newOne.count = 0;
    newOne.max = 0;
    
    return newOne;
}

void ResetTag( TagPassage * tag )
{
    tag->previous = -1;
    tag->count = 0;
}


int CountMax( list<bool> tab )
{
    // Count the max
    TagPassage passage = Create();
    
    for (list<bool>::iterator it = tab.begin(); it != tab.end(); ++it)
    {
        if (passage.previous > 0)
        {
            if (*it == false)
                ++passage.count;
            else
            {
                if ( passage.count > passage.max )
                    passage.max = passage.count;
                passage.count = 0;
                
            }
        }
        else if (*it == 1)
            passage.previous = 1;
            
    }
    
    return passage.max;
}

int CountZeroFromIterator( list<bool>::iterator begin, list<bool>::iterator end )
{
    int max = 0;
    
    while (*begin != 1 && begin != end)
        ++max;
    
    if (begin == end && *begin == 0)
        max = 0;
    
    return max;
}

// Get the new number
list<bool> GetBitNumber(unsigned int number) {
    list<bool> result;
    
    int rest = number;
    for (int i = GetMaxIndice(number); i >= 0; --i )
    {
        if ( (rest - ( pow(2, i) ) ) >= 0 ) {
            rest -= pow(2, i);
            result.push_back(1);
        }
        else
            result.push_back(0);
    }
    
    return result;
}

// Get maximun of the indice of a 2 power from a number
int GetMaxIndice(unsigned int number)
{
    return abs( log2(number) );
}
