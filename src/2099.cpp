#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Solution
{
public:
    struct num_index
    {
        int num;
        int index;
    };

    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<num_index> num_indexs;
        num_indexs.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            num_indexs.push_back(num_index{nums[i], i});
        }

        sort(num_indexs.begin(), num_indexs.end(),
             [](const num_index &left, const num_index &right)
             { return (left.num != right.num) ? (left.num > right.num) : (left.index < right.index); });

        num_indexs.resize(k);

        sort(num_indexs.begin(), num_indexs.end(),
             [](const num_index &left, const num_index &right)
             { return (left.index < right.index); });

        vector<int> result;
        result.reserve(k);
        for (const num_index &num_index_item : num_indexs)
        {
            result.push_back(num_index_item.num);
        }

        return result;
    }
};

int main()
{
    vector<int> nums{-1,-2,3,4};
    Solution().maxSubsequence(nums, 3);
}