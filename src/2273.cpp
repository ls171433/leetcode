#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    static bool compare(const string &word1, const string &word2)
    {
        array<int, 26> freq = {0};
        for (char c : word1)
        {
            ++freq[c - 'a'];
        }
        for (char c : word2)
        {
            --freq[c - 'a'];
        }

        for (int count : freq)
        {
            if (count != 0)
            {
                return false;
            }
        }
        return true;
    }

    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> result = {};
        result.push_back(words[0]);

        for (int i = 1; i < words.size(); ++i)
        {
            if (!compare(words[i], words[i - 1]))
            {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};
