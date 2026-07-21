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
    void reorderList(ListNode* head) {
        vector<ListNode*>v;
        ListNode*current = head;
        while(current!=NULL){
            v.push_back(current);
            current = current->next;
        }
        int n = v.size();
        current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        for(int i = 0; i<n; i++){
           
            if(i<n/2)v[i]->next = v[n-1-i];
            else if(i==n/2)v[i]->next = NULL;
            else v[i]->next = v[n-i];
        
    }
    }
};