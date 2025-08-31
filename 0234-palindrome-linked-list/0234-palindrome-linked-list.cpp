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
    ListNode* getmid(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow -> next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* &head){
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        
        ListNode* mid = getmid(head);
        ListNode* temp = mid->next;

        ListNode* first = head;
        ListNode* second = reverse(temp);

        while(second != NULL){
            if(first->val != second->val){
                reverse(temp);
                return false;
            }

            first = first->next;
            second = second -> next;
        }
        reverse(temp);
        return true;
    }
};