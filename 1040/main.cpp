#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> numMovesStonesII(vector<int> &stones)
    {
        sort(stones.begin(), stones.end());
        int min_steps;
        int max_steps;
        int size = stones.size();
        int test = std::min(stones[size - 1] - stones[1], stones[size - 2] - stones[0]);
        if (test == size - 2)
        {
            int test_2 = stones[size - 1] - stones[0];
            if (test_2 == size - 1)
            {
                min_steps = 0;
                max_steps = 0;
            }
            else if (test_2 == size)
            {
                min_steps = 1;
                max_steps = 1;
            }
            else
            {
                min_steps = 2;
                max_steps = std::max(stones[size - 1] - stones[1], stones[size - 2] - stones[0]) - size + 2;
            }
        }
        else
        {

            int max_count = 1;
            int i = 0;
            int j = 0;
            while (i < size)
            {
                while (stones[i] - stones[j] > size - 1)
                {
                    ++j;
                }
                int current_count = i - j + 1;
                if (current_count > max_count)
                {
                    max_count = current_count;
                }
                ++i;
            }
            min_steps = size - max_count;

            max_steps = std::max(stones[size - 1] - stones[1], stones[size - 2] - stones[0]) - size + 2;
        }
        return {min_steps, max_steps};
    }
};