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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        vector<int> ans;
        ListNode* temp = head;
        
        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        sort(ans.begin(), ans.end());

        ListNode* curr = new ListNode(0);
        temp = curr;
        for(int i=0; i<ans.size(); i++){
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }

        return curr->next;
    }
};