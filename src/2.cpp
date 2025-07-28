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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode sum_prev;

        int single_sum = 0;

        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *t3 = &sum_prev;

        while (t1 != nullptr || t2 != nullptr || single_sum > 0)
        {
            if (t1 != nullptr)
            {
                single_sum += t1->val;
                t1 = t1->next;
            }

            if (t2 != nullptr)
            {
                single_sum += t2->val;
                t2 = t2->next;
            }

            t3->next = new ListNode{single_sum % 10};
            t3 = t3->next;

            single_sum /= 10;
        }

        ListNode *sum = sum_prev.next;

        return sum;
    }
};
