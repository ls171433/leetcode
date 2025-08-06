#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size();

        int max_level = 0;
        while ((1 << max_level) < n)
        {
            ++max_level;
        }

        vector<int> segment_tree((1 << (max_level + 1)), 0);
        for (int i = 0; i < n; ++i)
        {
            segment_tree[(1 << max_level) - 1 + i] = baskets[i];
        }
        for (int i = (1 << max_level) - 2; i >= 0; --i)
        {
            segment_tree[i] = max(segment_tree[2 * i + 1], segment_tree[2 * i + 2]);
        }

        // for (int value : segment_tree)
        // {
        //     cout << value << ' ';
        // }
        // cout << endl;

        int result = 0;
        for (int fruit : fruits)
        {
            if (segment_tree[0] < fruit)
            {
                ++result;
                continue;
            }

            int i = 0;
            while (i < (1 << max_level) - 1)
            {
                if (segment_tree[2 * i + 1] >= fruit)
                {
                    i = 2 * i + 1;
                }
                else
                {
                    i = 2 * i + 2;
                }
            }
            segment_tree[i] = 0;
            while (i > 0)
            {
                i = (i - 1) / 2;
                segment_tree[i] = max(segment_tree[2 * i + 1], segment_tree[2 * i + 2]);
            }

            // for (int value : segment_tree)
            // {
            //     cout << value << ' ';
            // }
            // cout << endl;
        }

        return result;
    }
};
