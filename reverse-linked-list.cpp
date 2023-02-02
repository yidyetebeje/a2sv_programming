
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *left = head;
        ListNode *right = head->next;
        left->next = nullptr;
        while (right != nullptr)
        {
            ListNode *temp = right->next;
            right->next = left;
            left = right;
            right = temp;
        }
        return left;
    }
};