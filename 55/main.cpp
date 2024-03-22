#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return true;
        }
        int nmax = nums[0];
        for (int i = 0; i < nmax && i < nums.size(); ++i)
        {
            nmax = max(nmax, i + nums[i] + 1);
            if (nmax >= nums.size())
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    auto result = Solution().canJump(nums);
    cout << result << endl;
}
