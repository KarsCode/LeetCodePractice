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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<>>pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            while(lists[i]!=NULL){
                pq.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        ListNode *current = new ListNode(0);
        ListNode *dummy = current;
        while(!pq.empty()){
            current->next=new ListNode(pq.top());
            pq.pop();
            current=current->next;
        }
        return dummy->next;
    }
};