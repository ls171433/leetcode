#include <unordered_set>
#include <vector>

using namespace std;

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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode beforeHead(0, head);
        ListNode *prev = &beforeHead;

        while (prev->next != nullptr)
        {
            if (numSet.count(prev->next->val))
            {
                ListNode *toDelete = prev->next;
                prev->next = prev->next->next;
            }
            else
            {
                prev = prev->next;
            }
        }

        return beforeHead.next;
    }
};
