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
    void push(ListNode*& front,ListNode*& back,int data){
        ListNode* nn=new ListNode(data);
        if(!front){
            front=back=nn;
            return;
        }
        back->next=nn;
        back=nn;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans=NULL;
        ListNode* back=NULL;
        priority_queue<pair<int,ListNode*>,
        vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> q;
        for(auto &it:lists){
            if(it)
                q.push({it->val,it});
        }
        pair<int,ListNode*> curr;
        while(q.size()){
            curr=q.top();
            q.pop();
            push(ans,back,curr.first);
            if(curr.second->next){
                q.push({curr.second->next->val,curr.second->next});
            }
        }
        return ans;
    }
};