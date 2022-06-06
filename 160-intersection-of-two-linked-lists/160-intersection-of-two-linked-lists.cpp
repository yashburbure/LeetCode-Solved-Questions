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
        unordered_map<int,vector<ListNode*>> mp;
        unordered_map<int,int> ptr;
        ListNode* temp=headA;
        while(temp){
            mp[temp->val].push_back(temp);
            temp=temp->next;
        }
        ListNode* ans=NULL;
        temp=headB;
        ListNode* temp_ptr;
        while(temp){
            if(ptr[temp->val]<mp[temp->val].size()){
                if(mp[temp->val][ptr[temp->val]]==temp) ans=temp;
                ptr[temp->val]++;
            }
            if(ans) break;
            temp=temp->next;
        }
        return ans;
    }
};