class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int l, int r)
    {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        for(int i = 0; i < l - 1; i++){
            pre = pre->next;
        }
        cout << "pre->val: " << pre->val << endl;
        ListNode* cur = pre->next;
        ListNode* next = nullptr;
        for(int i = 0; i < r - l; i++){
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy->next;
    }
};