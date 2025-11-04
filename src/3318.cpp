#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        map<int, set<int, greater<int>>, greater<int>> count_nums;
        unordered_map<int, int> num_counts;

        for (int i = 0; i < k - 1 && i < nums.size(); ++i)
        {
            int num = nums[i];
            count_nums[num_counts[num]].erase(num);
            ++num_counts[num];
            count_nums[num_counts[num]].insert(num);
        }

        vector<int> result;
        for (int i = k - 1; i < nums.size(); ++i)
        {
            int insert_num = nums[i];
            int insert_count = num_counts[insert_num];
            if (insert_count > 0)
            {
                count_nums[insert_count].erase(insert_num);
            }
            ++insert_count;
            count_nums[insert_count].insert(insert_num);
            num_counts[insert_num] = insert_count;

            int sum = 0;
            int sum_count = 0;
            for (const auto &count_num : count_nums)
            {
                int part_sum = 0;
                int part_count = count_num.first;
                for (int part_num : count_num.second)
                {
                    // cout << part_num << endl;
                    part_sum += part_num;
                    ++sum_count;
                    if (sum_count >= x)
                    {
                        break;
                    }
                }
                sum += part_sum * part_count;
                if (sum_count >= x)
                {
                    break;
                }
            }
            // cout << endl;
            result.push_back(sum);

            int remove_num = nums[i - k + 1];
            int remove_count = num_counts[remove_num];
            count_nums[remove_count].erase(remove_num);
            --remove_count;
            if (remove_count > 0)
            {
                count_nums[remove_count].insert(remove_num);
                num_counts[remove_num] = remove_count;
            }
            else
            {
                num_counts.erase(remove_num);
            }
        }

        return result;
    }
};
