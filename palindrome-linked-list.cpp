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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode* traverse = head;
        while(traverse != nullptr){
            st.push(traverse);
            traverse = traverse->next;
        }
        traverse = head;
        while(!st.empty()){
            if(traverse->val != st.top()->val) return false;
            traverse = traverse->next;
            st.pop();
        }
        return true;
    }
};