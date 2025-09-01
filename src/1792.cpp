#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        int n = classes.size();
        priority_queue<pair<double, int>> pq;

        for (int i = 0; i < n; ++i)
        {
            const auto &class_ = classes[i];
            pq.emplace(static_cast<double>(class_[0] + 1) / static_cast<double>(class_[1] + 1) - static_cast<double>(class_[0]) / static_cast<double>(class_[1]), i);
        }

        for (int j = 0; j < extraStudents; ++j)
        {
            auto &top = pq.top();
            int i = top.second;
            pq.pop();

            auto &class_ = classes[i];
            ++class_[0];
            ++class_[1];
            pq.emplace(static_cast<double>(class_[0] + 1) / static_cast<double>(class_[1] + 1) - static_cast<double>(class_[0]) / static_cast<double>(class_[1]), i);
        }

        double result = 0;
        for (int i = 0; i < n; ++i)
        {
            const auto &class_ = classes[i];
            result += static_cast<double>(class_[0]) / static_cast<double>(class_[1]);
        }

        return result / static_cast<double>(classes.size());
    }
};
