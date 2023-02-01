/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* left = dummy;
        ListNode* right = left->next;
        while(right != nullptr){
            if(n <= 0){
                left = left->next;
            } else {
                n--;
            }
            right = right->next;
        }
        cout << left->val << endl;
        ListNode* temp = left->next;
        if(left->val == -1) head = head->next;
        else if(left->next != nullptr) left->next = left->next->next;
        else left->next = nullptr;
        return head;
    }
};