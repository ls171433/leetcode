#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        vector<int> word_count;
        word_count.resize(26, 0);

        for (char c : word)
        {
            ++word_count[c - 'a'];
        }

        int min_remove = INT_MAX;
        for (int current_count : word_count)
        {
            int current_remove = 0;
            for (int other_count : word_count)
            {
                if (other_count < current_count)
                {
                    current_remove += other_count;
                }
                else if (other_count > current_count + k)
                {
                    current_remove += other_count - current_count - k;
                }
            }

            if (current_remove <= min_remove)
            {
                min_remove = current_remove;
            }
        }

        return min_remove;
    }
};