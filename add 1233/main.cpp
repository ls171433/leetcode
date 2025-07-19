#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end());
        string temp = folder[0];
        temp.push_back('/');
        vector<string> result;
        for (const auto &file : folder)
        {
            if (file.size() >= temp.size() && file.substr(0, temp.size()) == temp)
            {
                ;
            }
            else
            {
                result.push_back(file);
                temp = file;
                temp.push_back('/');
            }
        }
        return result;
    }
};
