#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int number = 0;
        int digits = 0;
        for (auto it = s.rbegin(); it != s.rend(); ++it)
        {
            int current_binary = (*it == '1' ? 1 : 0);
            if (current_binary == 0)
            {
                ++digits;
            }
            else if (digits >= 31)
            {
                ;
            }
            else if (number + (current_binary << digits) <= k)
            {
                number += current_binary << digits;
                ++digits;
            }
        }
        return digits;
    }
};

int main()
{
    cout << (1 << 31) << endl;
    string s;
    s = "1001010";
    cout << Solution().longestSubsequence(s, 5) << endl;
    s = "00101001";
    cout << Solution().longestSubsequence(s, 1) << endl;
    s = "100110111111000000010011101000111011000001000111010001010111100001111110110010100011100100111000011011000000100001011000000100110110001101011010011";
    cout << Solution().longestSubsequence(s, 522399436) << endl;
}