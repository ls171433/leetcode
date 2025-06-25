#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        long long left = -2e10;
        long long right = 2e10;
        if (nums1.size() >= nums2.size())
        {
            swap(nums1, nums2);
        }
        while (left < right)
        {
            long long middle = (left + right) / 2;
            if (middle < 0 && left % 2 + right % 2 == 1)
            {
                --middle;
            }
            long long count = count_product(nums1, nums2, middle);
            if (count < k)
            {
                if (left == middle)
                {
                    return right;
                }
                left = middle;
            }
            else
            {
                if (right == middle)
                {
                    return right;
                }
                right = middle;
            }
        }
        return right;
    }

    long long count_product(const vector<int> &nums1, const vector<int> &nums2, long long middle)
    {
        long long count = 0;
        for (int num1 : nums1)
        {
            count += count_product(num1, nums2, middle);
        }
        return count;
    }

    long long count_product(long long num1, const vector<int> &nums2, long long middle)
    {
        if (num1 == 0)
        {
            if (middle >= 0)
            {
                return nums2.size();
            }
            else
            {
                return 0;
            }
        }
        else if (num1 < 0)
        {
            return nums2.size() - count_product(-num1, nums2, -middle - 1);
        }

        long long left_2 = 0;
        long long right_2 = nums2.size();
        while (left_2 < right_2)
        {
            long long middle_2 = (left_2 + right_2) / 2;
            if (num1 * nums2[middle_2] <= middle)
            {
                left_2 = middle_2 + 1;
            }
            else
            {
                right_2 = middle_2;
            }
        }
        return left_2;
    }
};

int main()
{
    vector<int> nums1{-4, -2, 0, 3};
    vector<int> nums2{2, 4};
    cout << Solution().kthSmallestProduct(nums1, nums2, 6) << endl;
}
