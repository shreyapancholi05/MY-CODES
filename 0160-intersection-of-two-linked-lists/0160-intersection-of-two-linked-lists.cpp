/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      /*  ListNode *a = headA;
        ListNode* b = headB;

        while(a != b){
            a = a ? (a->next) : headB;
            b = b ? (b->next) : headA;

       }
       return a;
       */
      /* unordered_set<ListNode*> s;
       while(headA){
        s.insert(headA);
        headA = headA->next;
       }
       while(headB){
            if(s.find(headB) != s.end()){
                return headB;
            }
                headB = headB->next;
            
       }
       return NULL;
       */
        int nA = 0;
        int nB = 0;
        ListNode* temp = headA;
        while(temp)
            nA++ , temp = temp -> next;
        temp = headB;
        
        while(temp)
            nB++, temp = temp->next;
        int diff = abs(nA - nB);
        if(nA > nB)
        while(diff--)
            headA = headA->next;
        else
        while(diff--)
        headB = headB->next;

        while(headA){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};