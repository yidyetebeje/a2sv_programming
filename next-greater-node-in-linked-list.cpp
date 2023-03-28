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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vi;
        stack<pair<int,int>> st;
        int i =  0;
        auto traverse = head;
        while(traverse != NULL){
            traverse = traverse->next;
            i++;
        }
        vi.resize(i);
        i = 0;
        while(head != NULL){
            while(!st.empty() && head->val > st.top().first){
                auto tp = st.top();
                vi[tp.second] = head->val;
                st.pop();
            }
            st.push(make_pair(head->val, i++));
            head = head->next;
        }
        return vi;
    }
};