#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int current[26] = {};
        int max = 0;
        for(size_t i = 0, j = 0; i < s.size(); ++i)
        {
            char ci = s[i];
            int& numi = (current[ci - 'a']);
            ++numi;
            while (numi >= 3)
            {
                char cj = s[j];\
                int& numj = (current[cj - 'a']);
                --numj;
                ++j;
            }
            int newmax = i - j + 1;
            if (newmax > max)
            {
                max = newmax;
            }
        }
        return max;
    }
};

int main()
{
    string s = "bcbbbcba";
    auto result = Solution().maximumLengthSubstring(s);
    cout << result << endl;
}