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
    ListNode* reverse(ListNode*& head,int range){
        ListNode* prevptr=NULL;
        ListNode* currptr=head;
        ListNode* nextptr;
        int i=1;
        while(i<=range){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
            i++;
        }
        return prevptr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==1){
            ListNode* temp=head;
            for(int i=1;i<=right;i++) temp=temp->next;
            ListNode* newhead=reverse(head,right-left+1);
            ListNode* temp2=newhead;
            while(temp2->next) temp2=temp2->next;
            temp2->next=temp;
            return newhead;
        }
        ListNode* newhead=head;
        ListNode* jt1_s=head;
        ListNode* jt2_s;
        int i;
        for(i=1;i<left-1;i++) jt1_s=jt1_s->next;
        // joint 1 start obt 
        jt2_s=jt1_s->next;
        // joint 2 start obt 
        ListNode* jt2_e=jt1_s->next;
        for(i=i+1;i<=right;i++){
            jt2_e=jt2_e->next;
            // cout<<i<<" "<<jt2_e->val<<endl;
        }
        // joint 2 end obt 
        // cout<<jt1_s->val<<" "<<jt2_s->val<<" "<<jt2_e->val<<endl;
        ListNode* jt1_e=reverse(jt1_s->next,right-left+1);
        jt1_s->next=jt1_e;
        jt2_s->next=jt2_e;
        return newhead;
    }
};