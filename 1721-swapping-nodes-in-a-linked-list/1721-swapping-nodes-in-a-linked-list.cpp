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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr;
        int it=1;
        ListNode* temp=head;
        while(temp){
            if(it==k) ptr=temp;
            temp=temp->next;
            it++;
        }
        int j=1;
        temp=head;
        while(j!=it-k){
            temp=temp->next;
            j++;
        }
        int sw=ptr->val;
        ptr->val=temp->val;
        temp->val=sw;
        return head;
    }
};