#include <array>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestSubsequenceRepeatedK(string s, int k)
    {
        array<int, 26> counts = {};
        for (char c : s)
        {
            ++counts[c - 'a'];
        }

        vector<char> available_letters;
        available_letters.reserve(26);
        for (char c = 'z'; c >= 'a'; --c)
        {
            if (counts[c - 'a'] >= k)
            {
                available_letters.push_back(c);
            }
        }
        if (available_letters.empty())
        {
            return "";
        }

        queue<string, list<string>> q;
        for (char c1 : available_letters)
        {
            for (char c2 : available_letters)
            {
                string new_current;
                new_current.push_back(c1);
                new_current.push_back(c2);
                q.push(std::move(new_current));
            }
        }
        string result;
        result.push_back(available_letters[0]);

        while (!q.empty())
        {
            const string &current = std::move(q.front());
            if (current.size() * k > s.size())
            {
                break;
            }
            if (consist(s, current, k))
            {
                if (current.size() > result.size())
                {
                    result = current;
                }
                for (char c : available_letters)
                {
                    string new_current = current;
                    new_current.push_back(c);
                    q.push(std::move(new_current));
                }
            }
            q.pop();
        }

        return result;
    }

    bool consist(const string &s, const string &t, int k)
    {
        int pos_s = 0;
        int pos_t = 0;
        int s_size = s.size();
        int t_size = t.size();
        while (pos_s < s_size)
        {
            if (s[pos_s] == t[pos_t % t_size])
            {
                ++pos_t;
                if (pos_t >= k * t_size)
                {
                    return true;
                }
            }
            ++pos_s;
        }
        return false;
    }
};

int main()
{
    cout << '"' << Solution().longestSubsequenceRepeatedK("letsleetcode", 2).size() << '"' << endl;
    cout << '"' << Solution().longestSubsequenceRepeatedK("bb", 2).size() << '"' << endl;
}
