#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freqs) {
        map<int, long long> current_freq;
        vector<long long> results;

        int last_num = -1;
        long long last_freq = 0;
        for (auto itn = nums.begin(), itf = freqs.begin();
            itn!= nums.end() && itf != freqs.end();
            ++itn, ++itf)
        {
            int num = *itn;
            int freq = *itf;
            current_freq[num] += freq;
            if (freq > 0)
            {
                if (last_num == num)
                {
                    last_freq += freq;
                }
                else
                {
                    if(last_freq < current_freq[num])
                    {
                        last_num = num;
                        last_freq = current_freq[num];
                    }
                }
            }
            else
            {
                if (last_num == num)
                {
                    last_freq += freq;
                    for(auto it : current_freq)
                    {
                        if (it.second > last_freq)
                        {
                            last_freq = it.second;
                            last_num = it.first;
                        }
                    }
                }
            }
            results.push_back(last_freq);
        }
        return results;
    }
};

int main()
{
    vector<int> nums = {2,3,2,1};
    vector<int> freqs = {3,2,-3,1};
    auto results = Solution().mostFrequentIDs(nums,freqs);
    for (const auto& result : results)
    {
        cout << result << endl;
    }
}