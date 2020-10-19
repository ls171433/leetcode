#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int longest = 0;
        size_t indexs[256];
        size_t repeated_index = (size_t)(-1);
        for (size_t &index : indexs)
        {
            index = (size_t)(-1);
        }

        for (size_t i = 0; i < s.size(); ++i)
        {
            unsigned char c = s[i];
            if (indexs[c] != (size_t)(-1))
            {
                if (repeated_index == (size_t)(-1))
                {
                    longest = max(longest, (int)(i));
                    repeated_index = indexs[c];
                }
                else
                {
                    longest = max(longest, (int)(i - repeated_index - 1));
                    repeated_index = max(repeated_index, indexs[c]);
                }
            }
            indexs[c] = i;
        }

        if (repeated_index == (size_t)(-1))
        {
            return s.size();
        }
        else
        {
            longest = max(longest, (int)(s.size() - repeated_index - 1));
        }

        return longest;
    }
};

int main()
{
    auto result = Solution().lengthOfLongestSubstring("abba");
    cout << result << endl;
}
