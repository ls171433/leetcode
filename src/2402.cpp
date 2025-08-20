#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct room
{
    int id = 0;
    int end_time = 0;
    int count = 0;
    room(int id, int end_time, int count) : id(id), end_time(end_time), count(count) {}
    room() = default;
};

bool operator<(const room &left, const room &right)
{
    if (left.end_time != right.end_time)
    {
        return left.end_time > right.end_time;
    }

    return left.id > right.id;
}

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());

        priority_queue<room> room_status;
        for (int i = 0; i < n; ++i)
        {
            room_status.emplace(i, 0, 0);
        }

        for (const auto &meeting : meetings)
        {
            while (room_status.top().end_time < meeting[0])
            {
                room new_room_status = room_status.top();
                room_status.pop();
                new_room_status.end_time = meeting[0];
                room_status.push(new_room_status);
            }

            room new_room_status = room_status.top();
            // cout << new_room_status.id << ' ' << new_room_status.end_time;
            room_status.pop();
            new_room_status.end_time += meeting[1] - meeting[0];
            ++new_room_status.count;
            // cout << ' ' << new_room_status.end_time << endl;

            room_status.push(new_room_status);
        }

        int result = 0;
        int max_count = 0;
        while (!room_status.empty())
        {
            const auto &old_room_status = room_status.top();
            if (old_room_status.count > max_count)
            {
                max_count = old_room_status.count;
                result = old_room_status.id;
            }
            else if (old_room_status.count == max_count)
            {
                result = min(result, old_room_status.id);
            }
            room_status.pop();
        }

        return result;
    }
};