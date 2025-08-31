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
int getlength(ListNode* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;
        ListNode* temp = head;
        int len = getlength(head);
        if (n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        for (int i = 1; i < (len - n); i++) {
            temp = temp->next;
        }
        ListNode* nodetodelete = temp->next;
        temp->next = nodetodelete->next;
        nodetodelete->next = NULL;
        delete nodetodelete;
        
        return head;
    }
};