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
    void push(ListNode*& head,int data){
        ListNode* nn=new ListNode();
        nn->val=data;
        if(head==NULL){
            head=nn;
            return;
        }
        ListNode* temp=head;
        while(temp->next) temp=temp->next;
        temp->next=nn;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode* prev=NULL;
        ListNode* next_=NULL;
        ListNode* temp=head;
        while(temp){
            if(temp->val<x){
                push(prev,temp->val);
            }
            else push(next_,temp->val);
            temp=temp->next;
        }
        if(prev){
            ListNode* newhead=prev;
            while(prev->next){
                prev=prev->next;
            }
            prev->next=next_;
            return newhead;
        }
        else return next_;
    }
};