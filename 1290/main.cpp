struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int result = 0;
        ListNode *node = head;
        while (node != nullptr)
        {
            result *= 2;
            result += node->val;
            node = node->next;
        }
        return result;
    }
};
