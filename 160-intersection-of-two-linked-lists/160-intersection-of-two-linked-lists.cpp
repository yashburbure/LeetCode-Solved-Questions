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
        ListNode* ans=NULL;
        stack<ListNode*> st1,st2;
        while(headA){
            st1.push(headA);
            headA=headA->next;
        }
        while(headB){
            st2.push(headB);
            headB=headB->next;
        }
        while(st1.size() && st2.size() && st1.top()==st2.top()){
            ans=st1.top();
            st1.pop();
            st2.pop();
        }
        return ans;
    }
};