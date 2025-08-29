/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution {
  public:
    int getlength(Node* &head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    int getMiddle(Node* head) {
        // code here
        Node* temp = head;
        int len = getlength(head);
        int ans = len/2;
        
        int cnt = 0;
        while(cnt < ans){
            temp= temp->next;
            cnt++;
        }
        return temp->data;
    }
};