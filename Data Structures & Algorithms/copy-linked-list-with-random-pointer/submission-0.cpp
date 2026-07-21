/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*org_current = head;
        Node*prev =  NULL;
        Node*curr = NULL;
        Node*newhead = NULL;
        int count = 0;
        unordered_map<Node*,Node*>m;
        while(org_current!=NULL){
            count++;
            curr = new Node(org_current->val);
            m[org_current] = curr;
            if(count==1)newhead = curr;
            if(prev!=NULL)prev->next = curr;
            prev  = curr;
            org_current = org_current->next; 
        }
        //allocate random now
        org_current = head;
        while(org_current!=NULL){
            m[org_current]->random = m[org_current->random];
        org_current = org_current->next;
        }
      return newhead;
    }
};