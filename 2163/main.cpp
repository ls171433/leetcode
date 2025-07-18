#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 3;

        long long first_sum = 0;
        priority_queue<int, vector<int>, less<int>> first_nums;
        long long third_sum = 0;
        priority_queue<int, vector<int>, greater<int>> third_nums;
        for (int i = 0; i < n; ++i)
        {
            first_sum += nums[i];
            first_nums.push(nums[i]);
            third_sum += nums[2 * n + i];
            third_nums.push(nums[2 * n + i]);
        }

        vector<long long> partial_first(n + 1, 0);
        vector<long long> partial_third(n + 1, 0);
        partial_first[0] = first_sum;
        partial_third[n] = third_sum;

        for (int i = 0; i < n; ++i)
        {
            first_sum += nums[n + i];
            first_nums.push(nums[n + i]);
            // cout << "first_nums.top() " << first_nums.top() << endl;
            first_sum -= first_nums.top();
            first_nums.pop();
            partial_first[i + 1] = first_sum;

            third_sum += nums[n * 2 - 1 - i];
            third_nums.push(nums[n * 2 - 1 - i]);
            // cout << "third_nums.top() " << third_nums.top() << endl;
            third_sum -= third_nums.top();
            third_nums.pop();
            partial_third[n - 1 - i] = third_sum;
        }

        long long result = LONG_LONG_MAX;
        for (int i = 0; i < n + 1; i++)
        {
            // cout << partial_first[i] << ' ' << partial_third[i] << endl;
            result = min(result, partial_first[i] - partial_third[i]);
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 1, 2};
    cout << solution.minimumDifference(nums) << endl; // Example usage
    nums = {7, 9, 5, 8, 1, 3};
    cout << solution.minimumDifference(nums) << endl; // Example usage
    return 0;
}
