#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct node
{
    map<string, node> sub_nodes;
    size_t hash_value = 0;
};

class Solution
{
public:
    unordered_map<size_t, int> hash_value_counts;
    vector<vector<string>> result;

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        node root_node;
        for (const auto &path : paths)
        {
            node *current_node = &root_node;
            for (const auto &folder : path)
            {
                current_node = &(current_node->sub_nodes[folder]);
            }
        }

        calculate_hash(&root_node);

        // for (const auto &hash_value_counts_pair : hash_value_counts)
        // {
        //     cout << hash_value_counts_pair.first << ' ' << hash_value_counts_pair.second << endl;
        // }

        get_result(&root_node, {});

        return result;
    }

    void calculate_hash(node *current_node)
    {
        string temp;
        for (auto &next_node_pair : current_node->sub_nodes)
        {
            calculate_hash(&next_node_pair.second);
            temp += next_node_pair.first;
            temp += ',';
            temp += to_string(next_node_pair.second.hash_value);
            temp += ',';
        }
        current_node->hash_value = hash<string>{}(temp);
        ++hash_value_counts[current_node->hash_value];
    }

    void get_result(node *current_node, const vector<string>& path)
    {
        if (current_node->hash_value == hash<string>{}(""))
        {
            if(!path.empty())
            {
                result.push_back(path);
            }
        }
        else if (hash_value_counts[current_node->hash_value] < 2)
        {
            if(!path.empty())
            {
                result.push_back(path);
            }
            for (auto &next_node_pair : current_node->sub_nodes)
            {
                vector<string> sub_path = path;
                sub_path.push_back(next_node_pair.first);
                get_result(&next_node_pair.second, sub_path);
            }
        }
    }
};
