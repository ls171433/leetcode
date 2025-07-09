#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        vector<pair<string, char>> temp;
        for (int i = 0; i < code.size(); ++i)
        {
            if (!isActive[i])
            {
                continue;
            }
            if (code[i].empty())
            {
                continue;
            }
            if (businessLine[i] != "electronics" &&
                businessLine[i] != "grocery" &&
                businessLine[i] != "pharmacy" &&
                businessLine[i] != "restaurant")
            {
                continue;
            }
            for (char c : code[i])
            {
                if (!((c >= '0' && c <= '9') ||
                      (c >= 'a' && c <= 'z') ||
                      (c >= 'A' && c <= 'Z') ||
                      c == '_'))
                {
                    goto next_loop;
                }
            }
            temp.push_back(std::make_pair(code[i], businessLine[i][0]));
        next_loop:
        }

        sort(temp.begin(), temp.end(), [](const pair<string, char> &left, const pair<string, char> &right)
             { return left.second != right.second ? (left.second < right.second) : (left.first < right.first); });

        vector<string> result;
        result.reserve(temp.size());
        for (auto& value : temp)
        {
            result.push_back(std::move(value.first));
        }

        return result;
    }
};
