#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

class TaskManager
{
public:
    unordered_map<int, pair<int, int>> taskId_userId_priority;
    set<pair<int, int>, greater<>> priority_taskId;
    TaskManager(vector<vector<int>> &tasks)
    {
        for (const auto &task : tasks)
        {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority)
    {
        priority_taskId.insert({priority, taskId});
        taskId_userId_priority[taskId] = {userId, priority};
    }

    void edit(int taskId, int newPriority)
    {
        auto &[userId, oldPriority] = taskId_userId_priority[taskId];
        priority_taskId.erase({oldPriority, taskId});
        priority_taskId.insert({newPriority, taskId});
        oldPriority = newPriority;
    }

    void rmv(int taskId)
    {
        auto &[userId, priority] = taskId_userId_priority[taskId];
        priority_taskId.erase({priority, taskId});
        taskId_userId_priority.erase(taskId);
    }

    int execTop()
    {
        if (priority_taskId.empty())
        {
            return -1;
        }

        auto &[priority, taskId] = *priority_taskId.begin();
        auto userId = taskId_userId_priority[taskId].first;
        taskId_userId_priority.erase(taskId);
        priority_taskId.erase(priority_taskId.begin());
        return userId;
    }
};
