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
    ListNode *mergeKLists(vector<ListNode *> &lists)
{
    vector<int> vi;
    for(auto li: lists){
        while(li){
            vi.push_back(li->val);
            li = li->next;
        }
    }
    if(vi.size() == 0) return NULL;
    sort(vi.begin(), vi.end());
    ListNode* dummy = new ListNode(0);
    ListNode* temp;
    ListNode* l1 = dummy;
    for(int i = 0; i < vi.size();i++){
        temp = new ListNode(vi[i]);
        l1->next = temp;
        l1 = l1->next;
    }
    return dummy->next;
}
};