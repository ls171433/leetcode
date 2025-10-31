#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        vector<int> result;
        result.reserve(2);
        
        unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.find(num) == seen.end())
            {
                seen.insert(num);
            }
            else
            {
                result.push_back(num);
                if (result.size() == 2)
                {
                    break;
                }
            }
        }

        return result;
    }
};
