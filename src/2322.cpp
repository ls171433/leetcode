#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();

        result = INT_MAX;
        total_xor = 0;
        num_edges.clear();
        num_edges.resize(n);
        for (const auto &edge : edges)
        {
            num_edges[edge[0]][edge[1]] = -1;
            num_edges[edge[1]][edge[0]] = -1;
        }

        for (int num : nums)
        {
            total_xor ^= num;
        }

        for (const auto &edge : edges)
        {
            int i = edge[0];
            int j = edge[1];
            {
                int part_xor_1 = calculate_part_xor(nums, i, j);

                for (auto &num_edge : num_edges[j])
                {
                    int k = num_edge.first;
                    if (k == i)
                    {
                        continue;
                    }

                    calculate_part_xor_2(nums, part_xor_1, k, j);
                }
            }
            {
                int part_xor_1 = calculate_part_xor(nums, j, i);

                for (auto &num_edge : num_edges[i])
                {
                    int k = num_edge.first;
                    if (k == j)
                    {
                        continue;
                    }

                    calculate_part_xor_2(nums, part_xor_1, k, i);
                }
            }
            num_edges[i][j] = -2;
            num_edges[j][i] = -2;
        }

        return result;
    }

    int calculate_part_xor(const vector<int> &nums, int i, int j)
    {
        auto it = num_edges[i].find(j);
        if (it->second != -1)
        {
            return it->second;
        }

        int part_xor = nums[i];
        for (auto &num_edge : num_edges[i])
        {
            if (num_edge.first == j)
            {
                continue;
            }

            part_xor ^= calculate_part_xor(nums, num_edge.first, i);
        }

        num_edges[i][j] = part_xor;
        num_edges[j][i] = total_xor ^ part_xor;

        return part_xor;
    }

    void calculate_part_xor_2(const vector<int> &nums, int part_xor_1, int k, int l)
    {
        for (auto &num_edge : num_edges[k])
        {
            if (num_edge.first != l)
            {
                calculate_part_xor_2(nums, part_xor_1, num_edge.first, k);
            }

            int part_xor_2 = calculate_part_xor(nums, k, l);
            if (part_xor_2 == -2)
            {
                continue;
            }

            int part_xor_3 = total_xor ^ part_xor_1 ^ part_xor_2;
            calculate_result(part_xor_1, part_xor_2, part_xor_3);
        }
    }

    void calculate_result(int part_xor_1, int part_xor_2, int part_xor_3)
    {
        int current_result = max(abs(part_xor_1 - part_xor_2), abs(part_xor_2 - part_xor_3));
        current_result = max(current_result, abs(part_xor_3 - part_xor_1));
        result = min(result, current_result);
    }

    int result = 0;
    int total_xor = 0;
    vector<unordered_map<int, int>> num_edges;
};
