#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> my_map;

        for (const auto& word : words)
        {
            my_map.insert(string{word.rbegin(), word.rend()});
        }

        string last_word;
        int length = 0;
        for (const auto& word : my_map)
        {
            if (word.size() >= last_word.size() && word.substr(0, last_word.size()) == last_word)
            {
            }
            else
            {
                length += (last_word.length() + 1);
            }
            last_word = word;
        }
        length += (last_word.length() + 1);
        return length;
    }
};

int main()
{
    vector<string> words = {"time", "me", "bell"};
    auto result = Solution().minimumLengthEncoding(words);
    cout << result << endl;
}
