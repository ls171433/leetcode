#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> count_map;
        unordered_map<int, int> count_map_temp;
        count_map[0] = 1;
        int max_or = 0;
        for (int num : nums) {
            count_map_temp.clear();
            max_or |= num;
            for (const auto& count : count_map) {
                count_map_temp[count.first | num] += count.second;
            }
            for (const auto& count_temp : count_map_temp) {
                count_map[count_temp.first] += count_temp.second;
            }
        }
        return count_map[max_or];
    }
};
