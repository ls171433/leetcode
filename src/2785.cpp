#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        int n = s.size();
        vector<char> vowels;
        vector<int> vowel_positions;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                vowels.push_back(s[i]);
                vowel_positions.push_back(i);
            }
        }
        sort(vowels.begin(), vowels.end());
        for (int i = 0; i < vowels.size(); ++i)
        {
            s[vowel_positions[i]] = vowels[i];
        }
        return s;
    }
};
