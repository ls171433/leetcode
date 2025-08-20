#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        unordered_set<int> result;
        unordered_set<int> current;

        for (int num : arr)
        {
            unordered_set<int> new_current;
            new_current.insert(num);
            for (int prev_num : current)
            {
                new_current.insert(prev_num | num);
            }
            current.swap(new_current);
            for (int new_num : current)
            {
                result.insert(new_num);
            }
        }

        return result.size();
    }
};
