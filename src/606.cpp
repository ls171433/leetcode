#include <iostream>
#include <sstream>
#include <string>

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
    void tree2str(stringstream &stream, TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        stream << node->val;
        if (node->right)
        {
            stream << "(";
            tree2str(stream, node->left);
            stream << ")(";
            tree2str(stream, node->right);
            stream << ")";
        }
        else if (node->left)
        {
            stream << "(";
            tree2str(stream, node->left);
            stream << ")";
        }
    }

    string tree2str(TreeNode *root)
    {
        stringstream stream;
        tree2str(stream, root);
        return stream.str();
    }
};