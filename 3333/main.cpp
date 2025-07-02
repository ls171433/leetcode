#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    static constexpr long long MOD = 1000000007;

    int possibleStringCount(string word, int k)
    {
        int single_count = 1;
        std::list<int> single_counts;
        for (int i = 1; i < word.size(); ++i)
        {
            if (word[i] == word[i - 1])
            {
                ++single_count;
            }
            else
            {
                single_counts.push_back(single_count);
                single_count = 1;
            }
        }
        single_counts.push_back(single_count);

        long long total = 1;
        for (int single_count : single_counts)
        {
            total *= single_count;
            total %= MOD;
        }

        int max_count = k - single_counts.size();
        if (max_count <= 0)
        {
            return total;
        }

        vector<long long> step_counts(max_count, 0);
        step_counts[0] = 1;
        for (int single_count : single_counts)
        {
            vector<long long> new_step_counts;
            new_step_counts.reserve(max_count);

            long long sum = 0;
            for (int i = 0; i < step_counts.size() && i < single_count; ++i)
            {
                sum += step_counts[i];
                sum %= MOD;
                new_step_counts.push_back(sum);
            }
            for (int i = single_count; i < step_counts.size(); ++i)
            {
                sum += step_counts[i];
                sum += MOD;
                sum -= step_counts[i - single_count];
                sum %= MOD;
                new_step_counts.push_back(sum);
            }

            step_counts = std::move(new_step_counts);
        }

        long long rest = 0;
        for (long long step_count : step_counts)
        {
            rest += step_count;
        }
        rest %= MOD;

        return (total + MOD - rest) % MOD;
    }
};

int main()
{
    cout << Solution().possibleStringCount("aabbccdd", 7) << endl
         << endl;
    cout << Solution().possibleStringCount("aabbccdd", 8) << endl
         << endl;
    cout << Solution().possibleStringCount("aaabbb", 3) << endl
         << endl;
}
