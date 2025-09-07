#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int min_char = 26;
        for (char c : s)
        {
            if (c > 'a')
            {
                min_char = min(min_char, c - 'a');
            }
        }
        return 26 - min_char;
    }
};
