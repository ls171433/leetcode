#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j - 1] > nums1[i])
            {
                // i is too small
                iMin = i + 1;
            }
            else if (i > iMin && nums1[i - 1] > nums2[j])
            {
                // i is too big
                iMax = i - 1;
            }
            else
            {
                // i is perfect
                int maxLeft = 0;
                if (i == 0)
                {
                    maxLeft = nums2[j - 1];
                }
                else if (j == 0)
                {
                    maxLeft = nums1[i - 1];
                }
                else
                {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }
                if ((m + n) % 2 == 1)
                {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == m)
                {
                    minRight = nums2[j];
                }
                else if (j == n)
                {
                    minRight = nums1[i];
                }
                else
                {
                    minRight = min(nums2[j], nums1[i]);
                }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }

    static int max(int lhs, int rhs)
    {
        return lhs >= rhs ? lhs : rhs;
    }

    static int min(int lhs, int rhs)
    {
        return lhs <= rhs ? lhs : rhs;
    }
};

int main()
{
    vector<int>nums1{1, 2};
    vector<int>nums2{3, 4};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
}
