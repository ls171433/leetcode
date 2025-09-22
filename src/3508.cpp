#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Router
{
public:
    int max_size = 0;
    deque<vector<int>> packets;
    unordered_map<int, deque<int>> destination_timestamps;

    int last_timestamp = -1;
    unordered_set<long long> last_timestamp_keys;

    Router(int memoryLimit)
    {
        max_size = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        long long key = (static_cast<long long>(source) << 32) | static_cast<long long>(destination);
        if (timestamp != last_timestamp)
        {
            last_timestamp = timestamp;
            last_timestamp_keys.clear();
        }
        else if (last_timestamp_keys.count(key))
        {
            return false;
        }
        last_timestamp_keys.insert(key);

        destination_timestamps[destination].push_back(timestamp);

        packets.push_back({source, destination, timestamp});
        if (packets.size() > max_size)
        {
            forwardPacket();
        }

        return true;
    }

    vector<int> forwardPacket()
    {
        if (packets.empty())
        {
            return {};
        }
        auto packet = packets.front();
        int source = packet[0];
        int destination = packet[1];
        int timestamp = packet[2];

        if (timestamp == last_timestamp)
        {
            long long key = (static_cast<long long>(source) << 32) | static_cast<long long>(destination);
            last_timestamp_keys.erase(key);
        }

        destination_timestamps[destination].pop_front();
        if (destination_timestamps[destination].empty())
        {
            destination_timestamps.erase(destination);
        }

        packets.pop_front();

        return packet;
    }

    int getCount(int destination, int startTime, int endTime)
    {
        auto it = destination_timestamps.find(destination);
        if (it == destination_timestamps.end())
        {
            return 0;
        }

        const auto &timestamps = it->second;
        auto left = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        auto right = lower_bound(timestamps.begin(), timestamps.end(), endTime + 1);
        return distance(left, right);
    }
};
