#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        if (s.empty())
        {
            return string();
        }

        string r(s.rbegin(), s.rend());

        size_t size = s.size();

        vector<size_t> ks(size, 0);
        ks[0] = 0;
        for (size_t i = 1; i < size; ++i)
        {
            size_t t = ks[i - 1];

            while (t > 0 && s[i] != s[t])
            {
                t = ks[t - 1];
            }
            if (s[i] == s[t])
            {
                ++t;
            }

            ks[i] = t;
        }

        vector<size_t> kr(size, 0);
        kr[0] = r[0] == s[0] ? 1 : 0;
        for (size_t i = 1; i < size; ++i)
        {
            size_t t = kr[i - 1];

            while (t > 0 && r[i] != s[t])
            {
                t = ks[t - 1];
            }
            if (r[i] == s[t])
            {
                ++t;
            }

            kr[i] = t;
        }

        return r.substr(0, size - kr.back()) + s;
    }
};

int main()
{
    string s = "aacecaaa";
    cout << Solution().shortestPalindrome(s) << endl;
}
