#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class FindSumPairs
{
public:
    vector<int> m_nums1;
    vector<int> m_nums2;

    unordered_map<int, int> m_counts2;

    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        m_nums1 = nums1;
        m_nums2 = nums2;

        for (int num2 : m_nums2)
        {
            ++m_counts2[num2];
        }
    }

    void add(int index, int val)
    {
        int num = m_nums2[index];
        auto it = m_counts2.find(num);
        --(it->second);
        if (it->second == 0)
        {
            m_counts2.erase(it);
        }

        num += val;
        ++m_counts2[num];
        m_nums2[index] = num;
    }

    int count(int tot)
    {
        int result = 0;

        for (int num1 : m_nums1)
        {
            auto it = m_counts2.find(tot - num1);
            if (it != m_counts2.end())
            {
                result += it->second;
            }
        }

        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */