#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];

            auto it = map.find(target - num);
            if (it != map.end())
            {
                return {it->second, i};
            }

            map[num] = i;
        }

        throw exception();
    }
};

int main()
{
    vector<int> nums{1, 49, 51};
    auto result = Solution().twoSum(nums, 100);
    for (const auto &index : result)
    {
        cout << index << endl;
    }
}
