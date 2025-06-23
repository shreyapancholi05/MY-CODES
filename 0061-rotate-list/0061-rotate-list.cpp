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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
        return head;

        int len = 1;
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
            len++;
        }

        k = k%len;
        if(k==0) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0 ; i<k; i++){
            fast = fast -> next;
        }

        while(fast -> next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* newhead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        
        return newhead;
    }
};