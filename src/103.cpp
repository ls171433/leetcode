#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;

        list<const TreeNode *> rlnodelist;
        list<const TreeNode *> lrnodelist;
        if (root != nullptr)
        {
            lrnodelist.push_back(root);
        }

        while (!lrnodelist.empty())
        {
            result.emplace_back();
            for (auto it = lrnodelist.begin(); it != lrnodelist.end(); ++it)
            {
                const auto &node = *it;
                result.back().push_back(node->val);
                if (node->left != nullptr)
                {
                    rlnodelist.push_back(node->left);
                }
                if (node->right != nullptr)
                {
                    rlnodelist.push_back(node->right);
                }
            }
            lrnodelist.clear();
            if (rlnodelist.empty())
            {
                break;
            }

            result.emplace_back();
            for (auto it = rlnodelist.begin(); it != rlnodelist.end(); ++it)
            {
                const auto &node = *it;
                result.back().push_back(node->val);
                if (node->left != nullptr)
                {
                    lrnodelist.push_back(node->left);
                }
                if (node->right != nullptr)
                {
                    lrnodelist.push_back(node->right);
                }
            }
            rlnodelist.clear();
            reverse(result.back().begin(), result.back().end());
        }

        return result;
    }
};

int main()
{
    TreeNode *tn = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    auto result = Solution().zigzagLevelOrder(tn);
    cout << '[' << endl;
    for (const auto &i : result)
    {
        cout << '[';
        for (const auto &j : i)
        {
            cout << j << ' ';
        }
        cout << ']' << endl;
    }
    cout << ']' << endl;
}
